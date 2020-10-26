
**講解一下如何避免 Race Condition** <br/>
解決此問題的基本概念，便是讓共享的資源在不同執行緒內可以受到控制，
但有時因為設計不良，便會出現競爭危害（race hazard）。又稱為競爭條件（race condition）
OS本身有提供 Semaphore 跟 Monitor 只要使用得當就可以避免這樣的問題。

下列程式會產生 race codition問題，我們無法確定最後 var 的值是 10 或是 20?
Parent thread:                         Child thread:

int var; // global variable

// create child thread
pthread_create(...)                          
var = 20;                              var = 10;
                                       exit
pthread_join(...)
printf("%d\n", var);

直覺的解法便是讓兩段設定var的程序有先後關係，如下例，
透過訊息的傳遞會讓設定 var 值的程序有 "happens-before" 關係，
也就是 var = 20; 一定會在 var = 10; 之前發生。因此最後的結果固定會是10。
Parent thread:                         Child thread:

int var;

// create child thread
pthread_create(...)                          
var = 20;
// send message to child
                                       // wait for message to arrive
                                       var = 10;
                                       exit

// wait for child
pthread_join(...)
printf("%d\n", var);

所以，若是某個記憶體內的資料，會同時被兩個不同的 thread進行存取，
我們可以先檢查這兩個 thread 寫入同份資料時是否存在 "happens-before relation"，
若不存在此關係，便存在 race condition. 



**Deadlock**
每一種資源都有一定的instances，像是可能有五個disk，不止一個的I/O devices，每一個

process 要利用資源都有以下三種階段
* 要求資源
* 使用資源
* 釋放資源

要死結必須要滿足以下四個條件
1. Mutual exclusion: 一個資源一次只能被一個process所使用
2. Hold and Wait: process取得一個資源之後等待其他的資源
3. No preemption: 資源只能由process自己釋放，不能由其他方式釋放
4. Circular wait: 每個process都握有另一個process請求的資源，導致每一個process都在等待另一個process釋放資源

針對提到的死結必須滿足的條件去做預防
Mutual exclusion: 對不可共用的資源類型而言，互斥一定成立，而可共用的資源類型，因為可以同時讀取相同檔案，所以一定不會產生。
Hold and Wait: process必須保證一個行程在要求一項資源時，不可以佔用任何其它的資源。
No preemption: 只要某個處理元要不到所要求的資源時，便把它已經擁有的資源釋放，然後再重新要求所要資源。
Circular Wait: 確保循環式等候的條件不成立，我們對所有的資源型式強迫安排一個線性的順序。

**atomic**
atomic transaction
因為一個 transaction 由一 instruction set 所組成
如果指明了某一 transaction 是 atomic
代表這個 transaction 在執行時, 其所屬的 instruction set 不是全部執行
不然就是全部不執行, 沒有那種執行一半的

**介紹一下Mutex、Semaphore、Spinlock**
30秒：
最大的差異在於 Mutex 只能由上鎖的 thread 解鎖，
而 Semaphore 沒有這個限制，
可以由原本的 thread 或是另外一個 thread 解開。
另外，Mutex 只能讓一個 thread 進入 critical section，
Semaphore 的話則可以設定要讓幾個 thread 進入。
這讓實際上使用 Mutex 跟 Semaphore 場景有很大的差別。
_
60秒 (cont.)：
舉例而言，Mutex 的兩個特性：
一個是只能有持鎖人解鎖、一個是在釋放鎖之前不能退出的特性，
讓 Mutex 叫常使用在 critical section 只能有一個 thread 進入，
而且要避免 priority inversion 的時候；
Semaphore 也能透過 binary semaphore 做到類似的事情，
卻沒有辦法避免 priority inversion 出現。
_
120秒 (cont.)：
而 Semaphore 更常是用在同步兩個 thread 或功能上面，
因為 Semaphore 實際上使用的是 signal 的 up 與 down，
讓 Semaphore 可以變成是一種 notification 的作用，
例如 A thread 執行到某個地方時 B thread 才能繼續下去，
就可以使用  Semaphore 來達成這樣的作用。

Mutex是一把鑰匙，一個人拿了就可進入一個房間，出來的時候把鑰匙交給隊列的第一個。
一般的用法是用於串行化對critical section代碼的訪問，
保證這段代碼不會被並行的運行。
(Function前用mutex lock，執行完unction後把mutex後釋出，
sleep給其他thread使用)
(A mutex is really a semaphore with value 1.)

Semaphore是一件可以容納N人的房間，如果人不滿就可以進去，
如果人滿了，就要等待有人出來。
對於N=1的情況，稱為binary semaphore。
一般的用法是，用於限制對於某一資源的同時訪問。

semaphore, mutex 會有睡覺的副作用, 
什麼是「睡覺」, 就是原本在執行的這段程式碼, 
在執行了 semaphore, mutex 的 function 之後, 
有可能會自己把 cpu 讓出去 (有點像是 coroutine 的 yeild), 要
等一會兒才會再繼續執行;
那 spinlock 呢? 答案很有趣, 在 kernel space 不會, 
甚是在 kernel space 的 spinlock 還需要關閉中斷, 
很多情境都比 user mode 複雜; 
在 user space 一樣會讓出 cpu, 
不過是被迫讓出去 (os 排程的管理), 而不是自己讓出去

spinlock
spinlock利用test and set這個指令看有沒有辦法取得lock 
因為是指令層級的操作所以有辦法達到atomic
當lock無法取得時會用polling的方式不斷嘗試
特別的地方是當他取得lock時 process將不會進入睡眠（沒有context switch）
效能會比semaphore好 因為他不做context switch可以一直執行

mutex vs spinlock
Mutex 屬於 sleep-waiting 類型的鎖。
Spin lock 屬於 busy-waiting 類型的鎖。
只能用在 thread 程式, 如果是兩個 process, 
你沒辦法用 mutex/spinlock 去保護共享資源, 
共享資源並非只有共享記憶體/變數, file, 硬體資源都是。

mutex vs  semaphore
mutex 除了擁有者外還有優先權的概念, 類似 thread 的優先權那樣
semaphore 不只能用在 thread 程式, 兩個不同的 process 也可以用 semaphore 共享資源。

不過 3 者的共同點都需要 atomic 的操作。

```
#include<stdio.h> 
#include<string.h> 
#include<pthread.h> 
#include<stdlib.h> 
#include<unistd.h> 
  
pthread_t tid[2]; 
int counter; 
pthread_mutex_t lock; 
  
void* trythis(void *arg) 
{ 
    pthread_mutex_lock(&lock); 
  
    unsigned long i = 0; 
    counter += 1; 
    printf("\n Job %d has started\n", counter); 
  
    for(i=0; i<(0xFFFFFFFF);i++); 
  
    printf("\n Job %d has finished\n", counter); 
  
    pthread_mutex_unlock(&lock); 
  
    return NULL; 
} 
  
int main(void) 
{ 
    int i = 0; 
    int error; 
  
    if (pthread_mutex_init(&lock, NULL) != 0) 
    { 
        printf("\n mutex init has failed\n"); 
        return 1; 
    } 
  
    while(i < 2) 
    { 
        err = pthread_create(&(tid[i]), NULL, &trythis, NULL); 
        if (error != 0) 
            printf("\nThread can't be created :[%s]", strerror(error)); 
        i++; 
    } 
  
    pthread_join(tid[0], NULL); 
    pthread_join(tid[1], NULL); 
    pthread_mutex_destroy(&lock); 
  
    return 0; 
} 

/**
Job 1 started
Job 1 finished
Job 2 started
Job 2 finished
**/
```
```
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t semaphore; // 旗標
int counter = 0;

// 子執行緒函數
void* child() {
  for(int i = 0;i < 5;++i) {
    sem_wait(&semaphore); // 等待工作
    printf("Counter = %d\n", ++counter);
    sleep(1);
  }
  pthread_exit(NULL);
}

// 主程式
int main(void) {

  // 初始化旗標，僅用於本行程，初始值為 0
  sem_init(&semaphore, 0, 0);

  pthread_t t;
  pthread_create(&t, NULL, child, NULL);

  // 送出兩個工作
  printf("Post 2 jobs.\n");
  sem_post(&semaphore);
  sem_post(&semaphore);
  sleep(4);

  // 送出三個工作
  printf("Post 3 jobs.\n");
  sem_post(&semaphore);
  sem_post(&semaphore);
  sem_post(&semaphore);

  pthread_join(t, NULL);

  return 0;
}
/**
Post 2 jobs.
Counter = 1
Counter = 2
Post 3 jobs.
Counter = 3
Counter = 4
Counter = 5
**/
```

```
|      Pi       |      Pi       |      Pi       |
| ------------- | ------------- | ------------- |
| repeat        | repeat        | repeat        |
|   A;          |   wait(S1);   |   wait(S1);   |
|   signal(S1); |   B           |   C           |
|   wait(S3);   |   signal(S2); |   signal(S3); |
| unitl False   | unitl False   | unitl False   |
```


**哲學家就餐問題** <br/>
死結 :哲學家從來不交談，這就很危險，可能產生死結，
每個哲學家都拿著左手的餐叉，永遠都在等右邊的餐叉（或者相反）

服務生解法
一個簡單的解法是引入一個餐廳服務生，哲學家必須經過他的允許才能拿起餐叉。
因為服務生知道哪只餐叉正在使用，所以他能夠作出判斷避免死結。

資源分級解法
在哲學家就餐問題中，資源（餐叉）按照某種規則編號為1至5，
每一個工作單元（哲學家）總是先拿起左右兩邊編號較低的餐叉，
再拿編號較高的。用完餐叉後，他總是先放下編號較高的餐叉，再放下編號較低的

Chandy/Misra解法
把筷子湊成對，讓要吃的人先吃，沒筷子的人得到一張換筷子券。
餓了，把換筷子券交給有筷子的人，有筷子的人吃飽了會把筷子交給給券的人。
有了券的人不會再得到第二張券。保證有筷子的都有得吃

**實現 Mutex**
Peterson’s Algorithm
使用兩個控制變數flag與turn。其中flag[n]的值為true，表示 ID 為n的 Process 希望進入該臨界區。變數turn保存有權訪問共享資源的 Process ID.
該演算法滿足解決臨界區問題的三個必須標準：互斥訪問、進入(No Deadlock)、有限等待(No Starvation)。
```
//flag[] is boolean array; and turn is an integer
flag[0]   = false;
flag[1]   = false;
int turn;

P0: flag[0] = true;
    turn = 1;
    while (flag[1] == true && turn == 1)
    {
        // busy wait
    }
    // critical section
    ...
    // end of critical section
    flag[0] = false;

P1: flag[1] = true;
    turn = 0;
    while (flag[0] == true && turn == 0)
    {
        // busy wait
    }
    // critical section
    ...
    // end of critical section
    flag[1] = false;
```
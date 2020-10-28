## malloc/free
### 一維陣列
這是使用 malloc 與 free 配置一維動態陣列的例子。
```
#include <stdio.h>
#include <stdlib.h>
int main() {
  int *dynArr; // 用來管理動態記憶體的指標
  int arrLen = 10; // 指定空間大小
  dynArr = malloc( arrLen * sizeof(int) );  // 取得記憶體空間

  /* 使用動態取得的記憶體空間 */
  
  free(dynArr); // 釋放記憶體空間
  return 0;
}
```
在 C 語言中動態配置的記憶體都必須配合指標來管理，
這個範例中我們需要動態建立一個整數（int）的陣列，
所以一開始先宣告一個整數的指標 dynArr，
接著使用 malloc 配置指定大小的記憶體空間給這個陣列使用。

malloc 在配置新的記憶體空間之後，
會傳回指向該空間第一個位元組（byte）的指標，
而在無法取得新的記憶體空間時（例如系統的記憶體不夠的時候），
就會傳回 NULL，所以在使用動態配置的記憶體空間之前，
要先檢查是否有配置成功。

當記憶體空間使用完之後，
再呼叫 free 來將該記憶體空間釋放掉，
這個動作不可以忘記，
否則就會造成記憶體洩漏（memory leak）的問題。

一般來說在程式中只要呼叫一次 malloc，
後續就要對應一次的 free 呼叫，
確保每一次配置的記憶體在使用完之後，
都有被妥善釋放。

### 二維陣列
這是拿一塊動態配置的記憶體空間，建立二維陣列的一種作法：
```
#include <stdio.h>
#include <stdlib.h>
int main() {
  int *matrix;

  int M = 10, N = 5; // 指定空間大小
  matrix = malloc( M * N * sizeof(int) ); // 取得記憶體空間
  memset(matrix, 0, M * N *  sizeof(int)); // 配置未初始化的記憶體空間

  // 使用動態取得的記憶體空間 matrix[i][j] = matrix[i*N+j]

  // 釋放記憶體空間
  free(matrix);
  return 0;
}
```
### calloc 函數
除了使用 malloc 之外，
也可以使用 calloc 配置初始化的陣列記憶體，
這兩個函數用法大同小異，
只是參數的指定方式不同，以及有無初始化而已，
透過 calloc 所取得的記憶體空間，
其值會被自動初始化為 0 或 NULL，
在釋放記憶體時跟 malloc 一樣都是呼叫free 函數並傳入指向記憶體的指標


```
不使用暫存變數交換兩個變數 ( Swap two variables without using a temporary variable )
a = a ^ b
b = a ^ b
a = a ^ b
```

```
pointer and &
int a = 3;
int &c= a;
printf("%d\n", c);
c *= a;
printf("%d\n", a);
printf("%d\n", c);
// 3 9 9
// c就是指到a的位置 簡單來說c完全等於a 不是只有得到a的值
```

## Stack/Heap
look at image
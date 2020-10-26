## Pointer
```
int a[] = {1, 2, 3, 4, 5, 6};
int *p = a;
*(p++) += 100;
*(++p) += 100;

for(int i=0; i<6; i++){
   printf("%d ", a[i]);
}
    
// 101 2 103 4 5 6
++ 在後 優先權最低  先取值 +=100 再 指標後移。
++ 在前 優先權最高  先指標後移 再取值 +=100。
```

```
char s[] = "0113256";
char* p = s;
printf("%c", *p++);     // 0  *p++ = *(p++) 先取值, 後指標下移 
printf("%c", *(p++));   // 1  
printf("%c", (*p)++);   // 1  (*p)++ 先取值	後值+1
printf("%c", *++p);     // 3  *++p = *(++p) 先指標下移 後取值
printf("%c", *(++p));   // 2
printf("%c", ++*p);     // 3  ++*p = ++(*p) 先值+1 後取值
printf("%c", ++(*p));   // 4
printf(s);              // 0123456

第一行字串為 : 0113234
第二行字串為 : 0123456
*p = 取值
p = 取指標位址
& :取變數在記憶體裡面的位置
* :取變數在記憶體裡面的值
++在前  =  先加1再取值
++在後  =  先取值後加1
```

```
int a[5] ={1,2,3,4,5};
int *p = (int *)(&a+1);

the value of *(a+1), (*p-1)?
Ans: 2, 6946571
```

## Function Pointer
```
例如三個副函式：

(1) int add(int);
(2) float add2(float);
(3) int add3(int,int);

並且宣告一個函式指標：
int (*pf)(int);

則：
(a.) pf = add;     //正確
(b.) pf = add2;   //錯誤，參數資料型態不匹配
(c.) pf = add3;   //錯誤，引入參數個數不匹配
```

```
int do_math(float arg1, int arg2) {
    return arg2;
}
 
int call_a_func(int (*call_this)(float, int)) {
    int output = call_this(5.5, 7);
    return output;
}
 
int final_result = call_a_func(do_math);
```

```
typedef int (*MathFunc)(float, int);
 
int do_math(float arg1, int arg2) {
    return arg2;
}
 
int call_a_func(MathFunc call_this) {
    int output = call_this(5.5, 7);
    return output;
}
 
int final_result = call_a_func(do_math);
```


## ifndef /define/ endif 作用和用法
ifndef/define/endif」主要目的是防止頭文件的重複包含和編譯，用法如下(.h文件)

```
#ifndef XX_H
#define XX_H
...
#endif
```

## struct, union and enum
struct
```
struct Employee{
	char name[30]; // 名字
	int age; //年齡
	char gender; // 性別，'M' or 'F'
	double salary; // 薪水
};
struct Employee employee; // 宣告變數employee，記得前面要加struct
```

union
```
union Var{ 
	char ch;
	int num1;
}; 
int main(void) {
	union Var var = {'x'}; // 初始化只能指定第一個成員
	// union Var var = {123}; 這句是不行的
	printf("var.ch = %c\n",var.ch); 
	printf("var.num1 = %d\n",var.num1); // 內容是無效的 
	
	var.num1 = 123;
	printf("var.ch = %c\n",var.ch); // 內容是無效的 
	printf("var.num1 = %d\n",var.num1);
	return 0;
}
```

enum 是一組由識別字所代表的整數常數
```
//除非特別指定，不然都是由0開始，接下來遞增1，例如以下語法：
enum week{Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday};

//以上從Sunday開始，各個識別字被依序設定為0到6，你也可以指定數值
enum week{Monday=1,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday};
```

```
int main(void) 
{
	enum week w;
	const char *day_name[] = {
		"","Monday","Tuesday","Wednesday",
		"Thursday","Friday","Saturday","Sunday" 
	};
	
	for(w=Monday; w <= Sunday; w++)
		printf("%s\n",day_name[w]);
	
    return 0;
}
```


## volatile
```
i = *pPort;      
j = *pPort;      
k = *pPort;     
```
以上的 i, j, k 很有可能被compiler最佳化而導致產生 i = j = k = *pPort;
也就是說只從pPort讀取一次, 而產生 i = j = k 的結果. <br/>
但是原本的程式的目的是要從同一個I/O port讀取3次的值給不同的變數, i, j, k的值很可能不同(例如從此
I/O port 讀取溫度), 因此i = j = k的結果不是我們所要的 <br/>

**一個參數可以同時是const也是volatile嗎? 解釋為什麼。** <br/>
是的。舉的例子是"只讀的狀態暫存器"。它是volatile因為它可能被意想不到地改變。它是const因為程式不應該試圖去修改它。


## lvalue and rvalue
Lvalue: 就是一個運算式後還保留其狀態的一個物件 就是Lvalue; 
也就是說 所有的變數(variables)包含nonmodifiable, const 的變數都是Lvalue. 這邊一個重點是 const的變數也是Lvalue. <br/><br/>

Rvalue: 就是一個運算式過後其狀態就不會被保留了, 
也就是一個暫存的數值 <br/><br/>

另一種說法(非完全正確,  但是可以依此來稍做判斷)
能出現在assignment 運算子(=)的左邊的稱為Lvalue, 而只能出現在右邊的稱為Rvalue

這邊只有說出現在左邊的是Lvalue, 但沒說Lvalue不能出現在右邊, 因此Lvalue在=運算子的左右兩邊都是被允許的, 
而Rvalue是不能出現在左邊的; 這邊有沒有注意到, Lvalue是可以被放到右邊的, 也就是說Lvalue也可以被當作Rvalue, 但是Rvalue就不能被當作是Lvalue


## Bitwise
判斷一個整數是不是 2 的次方
```
bool ispow2(int n) {
    return (n & -n) == n;
}
```

整數加一與減一 // 注意：比直接加一和減一還要慢。
```
void add_one(int& x) {
    return -~x; // ++x
}
void sub_one(int& x) {
    return ~-x; // --x
}
 ```

整數變號
 ```
void negative(int& x) {
    return ~x + 1;          // -x;
}
void negative(int& x) {
    return (x ^ -1) + 1;    // -x;
}
 ```

Reverse
```
0xaaaaaaaa = 10101010101010101010101010101010
0x55555555 = 01010101010101010101010101010101
0xcccccccc = 11001100110011001100110011001100
0x33333333 = 00110011001100110011001100110011
0xf0f0f0f0 = 11110000111100001111000011110000
0x0f0f0f0f = 00001111000011110000111100001111
0xff00ff00 = 11111111000000001111111100000000
0x00ff00ff = 00000000111111110000000011111111

x = (((x & 0xaaaaaaaa)>> 1) | ((x & 0x55555555) <<1));
x = (((x & 0xcccccccc)>> 2) | ((x & 0x33333333) <<2));
x = (((x & 0xf0f0f0f0)>> 4) | ((x & 0x0f0f0f0f) <<4));
x = (((x & 0xff00ff00)>> 8) | ((x & 0x00ff00ff) <<8));
return((x>> 16) | (x <<16));

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
(2 1) (4 3) (6 5) (8 7) (10 9) (12 11) (14 13) (16 15)
(4 3 2 1) (8 7 6 5) (12 11 10 9) (16 15 14 13)
(8 7 6 5 4 3 2 1) (16 15 14 13 12 11 10 9)
(16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1)
```

幾個1(每次減少一個1)
```
int bitcount(unsigned int n)
{
   int count = 0 ;
   while (n)
   {
      count++ ;
      n &= (n - 1) ; //關鍵演算之處
   }
   return count ;
}
```

## malloc free
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
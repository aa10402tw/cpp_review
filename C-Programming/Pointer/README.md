# Pointer

## 基礎語法
指標 (pointer)：一個指向某個儲存位址的變數，語法為
```
int *ptr = &var;
```
- & 取變數位址
- \* 表示為指標變數。 


函式指標 (function pointer)，語法為
```
void (*fptr)(type_a, type_b) = &func;
```
常用的地方如下
- 函式 sort 時傳入判斷準則
- multithread 傳函數進入建立 thread 的 API 中
- callback function (一種事件導向的函式)

## 指標判讀練習
指標判讀大原則為「從右讀到左」
```
int a;  // 一個int
int *a; // 一個指向int的指標
int **a; // 一個指向指標的指標，它指向的指標是指向一個int
int a[10]; // 一個有10個int的陣列
int *a[10]; // 一個有10個指標的陣列，該指標是指向一個int
int (*a)[10]; // 一個指向有10個int陣列的指標
int (*a)(int); // 一個指向函數的指標，該函數有一個整數型參數並返回一個整數
int (*a[10])(int); // 一個有10個指標的陣列，該指標指向一個函數，該函數有一個整數型參數並返回一個整數
```
注意宣告兩個指標時不能寫做 int* a, b; 因為前式等價於 int* a; int b;。連續宣告兩個指標用 int *a, *b;

## 指標與其他關鍵字混用
一樣右讀到左，例如：
```
const int * foo; // 一個 pointer，指向 const int 變數。
int const * foo; // 一個 pointer，指向 const int 變數。
int * const foo; // 一個 const pointer，指向 int 變數。
int const * const foo; // 一個 const pointer，指向 const int 變數。
```
關鍵字 volatile 等等判讀方式相同。


## 指標練習題
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

## 函式指標範例
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


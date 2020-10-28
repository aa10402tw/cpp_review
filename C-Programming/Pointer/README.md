## Pointer

### Basic
指標 (pointer)：一個指向某個儲存位址的變數，語法為 <br/>
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


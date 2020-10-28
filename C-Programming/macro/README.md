# Macro (巨集 #define)
#define 是巨集，在前置處理器 (preprocessor) 執行時(before compiler)處理，將要替換的程式碼展開做文字替換。define 語法範例如下：

## 常數巨集
```
#define PI 3.14
double circle_area(double radius) {
    return PI * radius * radius; // PI will be replaced by 3.14 
}
```

## 函數巨集
```
#define SUM(a,b) a+b
int main() {
    int a = SUM(3, 5);      // a = 3+5
    int b = SUM(2, 2)*5;    // b = 2+2*5 [Error!]
    printf("%d\n", a);   
    printf("%d\n", b);
}
// should use SUM(a,b) (a+b)
```

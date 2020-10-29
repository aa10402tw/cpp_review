
# Bitwise
## 如何表示負數
number| two's complement    | ones' complement    | sign/magnitude |
|------|:-------------:|------:|------:|
5 | 0000 0101 | 0000 0101 | 0000 0101 |
-5| 1111 1011 | 1111 1010 | 1000 0101 |
-x| ~x+1      | ~x        | flip the sign bit|

c allow all of three representation, but in practice every computer uses two's complement.

## 基礎語法
- 位移運算子(Shift operator):
    - 左移: x << y : x 左移 y 位元，左移出的位元會被丟棄，右側會補上 0
    - 右移: x >> y : x 右移 y 位元，右移出的位元會被丟棄，若為 Signed Int, 左側補上對應的 Sign (-10 >> 1 = -5)
    - 範例
```
5 << 1 = 10 // 00101 的全部位元向左移動一位數變成 01010. 
5 << 2 = 20 // 00101 的全部位元向左移動兩位數變成 10100. 
5 >> 1 = 2 // 00101 的全部位元向右移動一位數變成 00010. 
5 >> 2 = 1 // 00101 的全部位元向右移動一位數變成 00001.
```
- 邏輯運算子(Logic operator):
    - bitwise AND: &
    - bitwise OR: | 
    - bitwise XOR: ^ (exclusive OR)
    - bitwise NOT: ~ (one's complement)

## 應用題
取負數
```
int negative(int x)  {  
    return ~x + 1;          // -x;  
}  

int negative(int x)  {  
    return (x ^ -1) + 1;    // -x;  
}  
```
判斷奇數
```
int is_odd(int x)  {  
    return x & 1;   // equal to x % 2;  
}  
```
取得最低位數
```
int lowest_bit(int x) {  
    return x & -x;  
}
```

判斷一個整數是不是 2 的次方
```
/* if x is power of two, then the bit pattern must be 00..010..00
    -x = (~x) + 1 = (11..101..11) + 1 = 11..110..11
    so x & -x = 00..010..00 = x 
*/
bool ispow2(int n) {
    return (n & -n) == n;
}
```

整數加一與減一 // 注意：比直接加一和減一還要慢。
```
void add_one(int& x) {
    /* -x = ~x+1
       -~x = -(~x) = ~(~x)+1 = x+1 
    */
    return -~x; // ++x
}
void sub_one(int& x) {
    /* -x = ~x+1
       ~-x = ~(-x) = ~(~x+1) = x - 1  
    */
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

int count_num_of_one(unsigned int n) {  
    int i=0;  
    for ( ; n != 0; n >>= 1)  
        if (n & 1)  
            i += 1;  
    return i;  
} 
```

交換
```
void swap(int& x, int& y) {  
    x = x ^ y; // x' = x ^ y  
    y = x ^ y; // y' = x' ^ y = x ^ y ^ y = x  
    x = x ^ y; // x = x' ^ y' = x ^ y ^ x = y  
}  
```

絕對值
```
int abs(int x)  {  
    // x < 0 ? -x : x;  
    // x >> 31 = 111...111 (如果x是負數) or 000...000 (如果x是正數)  
    // x ^ (x>>31)  => 如果 x 為負數則將 x 的 0轉1, 1轉0, 如果 x 為正數, 則保持x 不變.  
    // (x ^ (x >> 31)) - (x >> 31) => 如果 x 為正數則 x-0=x , 如果 x 為負數則 ~x-(-1) = -x    
    return (x ^ (x >> 31)) - (x >> 31);  
}  

```

## 練習題
```
int c = 2 ^ 3;
printf("%d\n", c); 

/*
2   = 0010
3   = 0011
XOR = 0001 = 1
*/
```

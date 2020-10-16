## 定義
- Overloading (多載): 相同的模樣，擁有不同的行為 
- Overriding (覆寫): 

## Overloading
- Operator Overloading 
    - 靜態多型
    - 讓運算子(符號)有不同的意義
        - 例如重新定義 Custom Class 的比較運算子 <, =, > 
        - 例如重新定義 Custom Class 的算術運算子 +, -
        - 有些 operator 不能重載 (如 ?:, a::b, a.b)
    - Example
```
class 2DPoint
{
    ......
    bool operator==(const 2DPoint& p2) {
        return (this->x==p2.x) && (this->y==p2.y);
    }
    2DPoint operator+(2DPoint p) {
        return 2DPoint(x+p.x, y+p.y);
    }
    void operator=(2DPoint p) { // 如果要連續=需要回傳 *this
        x = p.x;
        y = p.y;
    }
}
/* In reality 
p3 = p1 + p2 
-> p3 = p1.operator+(p2);
-> p3.operator=(p1.operator+(p2))
*/
```

- Function Overloading
    - 靜態多型
    - 同樣名稱的函數有多種格式，或說多個函數共用一個函數名稱
    - 可以定義兩個有相同名稱的函數，但函數簽名 (Signature) 必須不同 (引數串列的引數數目、引數型態)
    - Example
```
void myPrint(std::string s);
void myPrint(int num, int width);

print("Test");
print(15, 5);
```
## Overriding

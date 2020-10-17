## 定義
- Overloading (多載): 相同的模樣(簽名/運算子)，但擁有不同的行為 
- Overriding (覆寫): 子類別將父類別函式重新定義以符合自身所需

## Overloading
- Function Overloading 
    - 靜態多型 (Static Polymorphism)
    - 同樣名稱的函數有多種格式，或說多個函數共用一個函數名稱
    - 可以定義兩個有相同名稱的函數，但函數簽名 (Signature) 必須不同 (引數串列的引數數目、引數型態)
    - Example
```
void myPrint(std::string s);
void myPrint(int num, int width);

print("Test");
print(15, 5);
```

- Operator Overloading 
    - 靜態多型(Static Polymorphism)
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
    2DPoint operator+(const 2DPoint p) {
        return 2DPoint(x+p.x, y+p.y);
    }
    void operator=(const 2DPoint p) { // 如果要連續=需要回傳 *this
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

## Overriding
Function overriding is a feature that allows us to have a same function in child class which is already present in the parent class. A child class inherits the data members and member functions of parent class, but when you want to override a functionality in the child class then you can use function overriding. It is like creating a new version of an old function, in the child class.

```
class BaseClass {
public:
   void disp(){
      cout<<"Function of Parent Class";
   }
};
class DerivedClass: public BaseClass{
public:
   void disp() {
      cout<<"Function of Child Class";
   }
};
```

## Virtual Function
- 是一種宣告在基底類別中的成員函數
- 提供執行時期多型 (Runtime Polymorphism) 的機制（若沒有宣告 virtual，會根據宣告的 Datatype 呼叫，為靜態多型）
- 使用 virtual 關鍵字
- 通常衍生類別會 override 它
- Pure Virtual Function 
    - virtual void print(int m)=0;
    - 特性：衍生類別一定要 override 基底類別中所有的純粹虛擬函數
    - 用途
        - 設計共同的使用介面的類別(衍生類別負責實作)
        - 防止使用者產生不允許存在的物件
- 抽象類別(abstract class): 當類別至少含有一個 Pure Virtual Function 時
    - 不能用來產生物件
- When you refer to a derived class object using a **pointer** or a **reference** to the base class, you can call a virtual function for that object and execute the derived class’s version of the function.

```
class car {
    virtual void move() { cout << “car move”; }
};
class Benz: public car {
    void move() { cout << “Benz move”;}
};
class Volvo: public car {
    void move() { cout << “Volvo move”;}
};
void demo(car& c) { c.move(); }

void main() { 
    Benz b;
    demo(b); 
}
```
## Static class members
- 被所有此類別的所有物件所共有
- 一般來說，所有的物件都有一份COPY
- 很像全域變數, 但是有類別範圍
    - 只能夠被同一個類別的物件所存取
- 可以是變數或者函式
    - public, private, or protected

## Destructor
- Special member function 
    - Performs "termination housekeeping", before system reclaims object’s memory
- Same name as class, Preceded with tilde (~)
- No arguments, Cannot be overloaded
    - if no explicit destructor, Compiler creates "empty" destructor”
- No return type

## Example 
```
class SalesPerson 
{
public:
    SalesPerson(); // default constructor
    SalesPerson(int[]); // constructor overloading
    void setSales(int, double); // set 
    void printAnnualSales(); 
    ~SalesPerson(); // destructor
private:
    double totalAnnualSales(); // prototype for utility function
    double sales[12]; // 12 monthly sales
}

/* Only the simplest and most stable member functions (i.e., whose implementations are unlikely to change) should be defined in the class header. */

/* Member functions defined outside class using scope resolution operator (::) */
SalesPerson::SalesPerson() {
    for (int i=0; i<12; i++)
        sales[i] = 0.0;
}
```

## Common Error
- Attempting to initialize a non-static data member of a class explicitly in the class definition is a syntax error. <br/>
- A constructor can call other member functions of the class, such as set or get functions, but because the constructor is initializing the object, the data members may not yet be in a consistent state. Using data members before they have been properly initialized can cause logic errors.

## 如何呼叫 constructor
宣告變數時, 例: Complex x(3,-4), y(2,-1); 注意: local static 變數的 constructor 在該副程式第一次執行時起動. <br/>
以 new 產生變數時, 例: Complex* p = new Complex(4,-3); <br/>
注意: 即使宣告變數或使用 new 時不傳參數, 仍舊有一個 constructor 會自動執行 -- 也就是那個不需要參數的 constructor.

## 如何呼叫 destructor
No, never do that!

## Copy constructor (複製建構子)
宣告方式: Complex(Complex const& x) <br/>
使用方式: 例 Complex x(3,4); Complex y(x);
注意: 在變數宣告中, complex y = x; 會呼叫到 copy constructor; 但是在程式中, y = x; 呼叫到的則是 assignment operator.
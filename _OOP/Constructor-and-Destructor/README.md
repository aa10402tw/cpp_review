## 定義
Constructor (建構子) 與 destructor (除構子): special member function in class, Compiler 會對它們作特殊的處理

## Constructor
- Special member function (Initialize data members)
- Same name as class
- Called when object instantiated
- Several constructors (Function overloading)
    - Default constructors
    Defaults all arguments or Explicitly requires no arguments
    - 如果程式設計師宣告了任何一個 constructor (不論是有參數的版本或沒有參數的版本), 則內建的 (沒有參數的) constructor 自動消失
- No return type

## Destructor
- Special member function 
    - Performs "termination housekeeping", before system reclaims object’s memory
- Same name as class, Preceded with tilde (~)
- No arguments, Cannot be overloaded
    - No explicit destructor, Compiler creates "empty" destructor”
- No return type

## Common Error
Attempting to initialize a non-static data member of a class explicitly in the class definition is a syntax error. <br/>
A constructor can call other member functions of the class, such as set or get functions, but because the constructor is initializing the object, the data members may not yet be in a consistent state. Using data members before they have been properly initialized can cause logic errors.

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
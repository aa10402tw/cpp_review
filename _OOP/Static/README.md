## Static class members (data or function)
- 被所有此類別的所有物件所共有 (belong to class, not the object (instace of class))
    - 所有以此 class 生成出來的 instance 都共用這個 variable。
    - 最經典的範例就是用來計數這個 class 總共生成了多少個 instance。
- 一般來說，所有的物件都有一份COPY
- 很像全域變數, 但是有類別範圍
    - 只能夠被同一個類別的物件所存取
- 可以是變數或者函式
    - public, private, or protected
- static member function 只能使用 class 中的 static variable/function，不能使用非 static 的 member 
    - 屬於 class 的東西只能使用屬於 class 的東西，不能使用屬於 object 的東西

## Static variable in function
- 一般我們寫 funcion 時，裡面宣告的變數在 funcion 結束之時也會跟著消失。
- 但如果我們在某個變數之前加上 static，該變數就不會因為 function 結束而消失。
- 最經典的例子大概就是要計算這個 function 被呼叫幾次
```
void greeting() {
    static int counter = 0;
    counter += 1;
    cout << "Greeting function has been called " 
         << counter << "times" << endl;
}
```

## Static global variable
- 背景：變數在不同檔案中要共用，只要 include 某個檔案以後，就可以使用其中的變數
    - 但假如 a.cpp 跟 b.cpp 裡面各自宣告了一個在 global variable bool debug
    - link 的過程中就會因為名字相同而產生衝突的錯誤
- static 的用意就是要讓這樣的 global variable 只限定在該檔案內，而不是整個程式中
    - 例如 如果我們把 a.cpp 和 b.cpp 中的 bool debug 在宣告時前面都加上 static
    - 這樣 compiler 在處理前期替換掉的名字就會不同，因此 link 的過程中也不會有名字衝突的問題

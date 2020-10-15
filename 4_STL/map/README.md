map： map內部實現了一個紅黑樹，該結構具有自動排序的功能，因此map內部的所有元素都是有序的，紅黑樹的每一個節點都代表著map的一個元素，因此，對於map進行的查找，刪除，添加等一系列的操作都相當於是對紅黑樹進行這樣的操作，故紅黑樹的效率決定了map的效率。 <br/>
unordered_map: unordered_map內部實現了一個哈希表，因此其元素的排列順序是雜亂的，無序的  <br/>

Table of Contents
=================
  * [Init Map](#Init-Map)
  * [Basic Operation](#Basic-Operation)

## Init-Map
```
// 宣告一個 Unordered Map
std::unordered_map<std::string, int> stringCount;
    
// operator=
std::unordered_map<std::string, int> myMap = stringCount;
```

## Basic-Operation
```
//判斷是否為空
myMap.empty();

//獲取元素個數 size()
myMap.size();

//查詢函式 find() 通過給定主鍵查詢元素
unordered_map<int>::iterator it = myMap.find("OUO");

//插入函式 
myMap.insert(std::make_pair("OUO", 1)); // Insert
myMap["OUO"] = 1; // Subscripting

//刪除 erase(key) 
myMap.erase("OUO");
myMap.erase(myMap.begin());
```
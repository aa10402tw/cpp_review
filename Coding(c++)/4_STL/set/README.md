set 基於紅黑樹實現，紅黑樹具有自動排序的功能，因此 set 內部所有的數據，在任何時候，都是有序的。搜尋/插入/刪除時間複雜度為 O(logN)。<br/>
unordered_set它的實現基於hashtable, 搜尋/插入/刪除時間複雜度為 O(1)，所花空間較大。<br/>
缺點 : 若是 Custom Class 作為 Key, 需要自定義 hash function <br/>

Table of Contents
=================
  * [Init Set](#Init-Set)
  * [Basic Operation](#Basic-Operation)
  * [Example Usage](#Example-Usage)

## Init-Set
```
// 宣告一個 Unordered Set
unordered_set<int> s1;
    
// operator=
unordered_set<int> s2;
s2 = s1;
```

## Basic-Operation
```
//判斷是否為空
s1.empty();

//獲取元素個數 size()
s1.size();

//查詢函式 find() 通過給定 key 查詢元素位置（找不到則 it == set.end())
unordered_set<int>::iterator it = s1.find(1);

// 插入函式 insert()
s1.insert(1);

// 刪除 (erase)
s1.erase(1); // erase(key)
s1.erase(s1.begin()); //erase(iterator) 
```

## Example-Usage
```
std::vector<int> removeDuplicate(std::vector<int>& nums) {
  std::vector<int> result;
  std::unordered_set<int> S;
  for (int num:nums) {
    if (S.find(num) == S.end()) {
      S.insert(num);
      result.push_back(num);
    }
  }
  return result;
}
```
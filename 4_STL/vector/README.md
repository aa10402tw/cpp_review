Table of Contents
=================
  * [Init Vector](#Init-Vector)
  * [Basic Operation](#Basic-Operation)

## Init-Vector
```
// Create an empty vector 
vector<int> vect;

// Create a vector with some values
vector<int> number = {10, 20, 30};

// Create a vector of size n with all values as 10. 
vector<int> vect(n, 10);
```

## Basic-Operation
```
// Copy Vector (deep copy from vector 1 to vector 2)
std::vector<int> vec2(vec1);  // constructor method 
vec2.assign(vec1.begin(), vec1.end()); // Copying vector by assign function
vec2 = vect; // Using assignment operator to copy one vector to other

// Add Element to vector
vec.push_back(new_element); // push_back 的效率很高, push_front的效率非常低，不建議使用
vec1.insert(vec1.end(), vec2.begin(), vec2.end()); // Append vec2 to vec1 (insert需要把插入位置元素往後移，除非插最後否則不建議使用)

// Remove elment from vector (erase需要把刪除位置後面的元素全部前移，效率比較低，除非刪除最後否則不建議使用)
vec.erase (vec.begin()+5); // erase the 6th element
vec.erase(begin, end); // 刪除[begin, end)區間的元素 

// Swap element
std::swap(vec[i], vec[j]);

// Reverse vector (Need include <algorithm>)
std::reverse(vec.begin(), vec.end());

// Sort Primitive type (Need include <algorithm>)
std::sort(vec.begin(), vec.end());

// Sort custom class (Need include <algorithm>)
std::vector<std::vector<int>> intervals = {{3,5}, {0,4}, {7,10}}
bool compareInterval(std::vector<int> i1, std::vector<int> i2) { return (i1[0] < i2[0]);}
std::sort(intervals.begin(), intervals.end(), compareInterval);
```



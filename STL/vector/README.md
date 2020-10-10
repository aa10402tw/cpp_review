Table of Contents
=================
  * [Copy vector](#Copy-Vector)
  * [Sort vector](#Sort-Vector)

## Copy-Vector
```
std::vector<int> vec = {1,2,3};
std::vector<int> vec2;
vec2.assign(vec.begin(), vec.end());
```

## Sort-Vector
Sort primitive type 
```
std::sort(vec.begin(), vec.end());
```

Sort custom class
```
std::vector<std::vector<int>> intervals = {{3,5}, {0,4}, {7,10}}
bool compareInterval(std::vector<int> i1, std::vector<int> i2) { 
	return (i1[0] < i2[0]);
}
std::sort(intervals.begin(), intervals.end(), compareInterval);
```
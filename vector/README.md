Table of Contents
=================
  * [Copy vector](#Copy-Vector)
  * [Sort vector](#Sort-Vector)

## Copy-Vector
```
vec2.assign(vec.begin(), vec.end());
```

## Sort-Vector
standard sort 
```
std::sort(vec.begin(), vec.end());
```

sort custom class
```
bool compareInterval(std::vector<int> i1, std::vector<int> i2) { return (i1[0] < i2[0]);}
std::sort(intervals.begin(), intervals.end(), compareInterval);
```
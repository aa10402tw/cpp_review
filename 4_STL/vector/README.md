Table of Contents
=================
  * [Init Vector](#Init-Vector)
  * [Copy vector](#Copy-Vector)
  * [Sort vector](#Sort-Vector)
  * [Remove-Element](#Remove-Element)

## Init-Vector
```
// Create an empty vector 
vector<int> vect;

// Create a vector with some values
vector<int> number = {10, 20, 30};

// Create a vector of size n with all values as 10. 
vector<int> vect(n, 10);
```

## Copy-Vector
```
// constructor method (Deep copy) 
vector<int> vect2(vect1); 

// Copying vector by assign function  (Deep copy) 
vec2.assign(vec1.begin(), vec1.end());

// Using assignment operator to copy one vector to other (Deep copy) 
vect2 = vect1;
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

## Remove-Element
```
// erase the 6th element
myvector.erase (myvector.begin()+5);
```
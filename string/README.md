Table of Contents
=================
  * [Copy string](#Copy-String)
  * [Char to String](#Char-to-String)

## Copy-String
Don't use strcpy (only use it for C-Style strings)
```
std::string a = "text";
std::string b = a; // copy a into b
```

## Sort-String
1. operator += 
```
char c = 'A';
std::string s;
s += c;
```
2. operator = 
```
char c = 'A';
std::string s;
s = c;
```
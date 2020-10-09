Table of Contents
=================
  * [Copy string](#Copy-String)
  * [Char to String](#Char-to-String)
  * [Int and String](#Int-and-String)

## Copy-String
Don't use strcpy (only use it for C-Style strings)
```
std::string a = "text";
std::string b = a; // copy a into b
```

## Char-to-String
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

## Int-and-String
std::to_string() <br/>
std::stoi()
```
/* Int to String */
int x = 10;
std::string s = std::to_string(x);

/* String to Int */
std::string s = "20";
int x = std::stoi(s);
```
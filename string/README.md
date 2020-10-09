Table of Contents
=================
  * [Copy string](#Copy-String)
  * [Char to String](#Char-to-String)
  * [Int and String](#Int-and-String)
  * [Parse Line](#Parse-Line)

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

## Parse-Line
std::istringstream iss
```
/* Get numbers from line */
std::string line = "1 2 3";
std::vector<int> nums;
int num;
std::istringstream iss(line);
while(iss >> num) nums.push_back(num);

/* Get String from line */
std::string line = "1 2 3";
std::string s;
while(line >> s) do_something();
```
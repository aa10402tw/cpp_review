Table of Contents
=================
  * [Basic Operation](#Basic-Operation)

## Basic-Operation
#### Copy-String
Don't use strcpy (only use it for C-Style strings)
```
std::string a = "text";
std::string b = a; // copy a into b
```

#### Char-to-String 
```
char c = 'A';
// operator += 
std::string s1;
s1 += c;

//operator = 
std::string s2;
s2 = c;
```

#### Type conversion (int <-> string)
```
/* Int to String */
int x = 10;
std::string s = std::to_string(x);

/* String to Int */
std::string s = "20";
int x = std::stoi(s);
```

#### Parse-Line
std::istringstream iss
```
/* Get numbers from line */
std::string line = "1 2 3";
std::vector<int> nums;
int num;
std::istringstream iss(line);
while(iss >> num) nums.push_back(num);

/* Get String from line */
std::string line = "dog cat apple";
std::string s;
while(line >> s) do_something();
```

#### Substring
```
std::string s = "0123456789";

// str.substr(startPos)
s1 = s.substr(5) // s1 = "56789"

// str.substr(startPos, length)
s2 = s.substr(2, 3) // s1 = "234"
```
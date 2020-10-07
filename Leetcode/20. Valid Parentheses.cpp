#include <iostream>
#include <string>
#include <stack>


/* Stack Usage
1. Init 
std::stack<char> myStack;

2. Push
myStack.push(c);

3. Pop the top 
char c1 = myStack.top();
myStack.pop();
*/ 

bool isValid(std::string s) {
	std::stack<char> myStack;
	for (int i = 0; i < s.size(); i++) {
		char c = s.at(i);
		if (c == '(' || c == '[' || c == '{')
			myStack.push(c);
		if (c == ')' || c == ']' || c == '}') {
			if (myStack.size() == 0)
				return false;
			char c1 = myStack.top();
			if (c == ')' && c1 != '(') return false;
			if (c == ']' && c1 != '[') return false;
			if (c == '}' && c1 != '{') return false;
			myStack.pop();
		}
	}
	return (myStack.size() == 0);
}

int main() {
	std::string s;
	std::cin >> s;
	std::cout << isValid(s);
}

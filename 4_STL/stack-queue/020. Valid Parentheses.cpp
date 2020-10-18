/* [Question Description]
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:

# Example 1
Input: s = "()"
Output: true

# Example 2
Input: s = "()[]{}"
Output: true

# Example 3
Input: s = "(]"
Output: false

# Example 4
Input: s = "([)]"
Output: false

# Example 5
Input: s = "{[]}"
Output: true
*/ 
#include <iostream>
#include <string>
#include <stack>

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
*/

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

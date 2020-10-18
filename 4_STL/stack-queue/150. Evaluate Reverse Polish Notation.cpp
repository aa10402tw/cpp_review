/* [Question Description]
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.

# Example 1
Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

# Example 2
Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

# Example 3
Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/ 
#include <iostream>
#include <vector>
#include <stack>
#include <string>

int evalRPN(std::vector<std::string>& tokens) {
	std::stack<int> S;
	for (int i = 0; i < tokens.size(); i++) {
		std::string token = tokens[i];
		if (token.size() == 1 && (token == "+" || token == "-" || token == "*" || token == "/")) {
			int v2 = S.top();
			S.pop();
			int v1 = S.top();
			S.pop();
			if (token == "+") S.push(v1 + v2);
			if (token == "-") S.push(v1 - v2);
			if (token == "*") S.push(v1 * v2);
			if (token == "/") S.push(v1 / v2);
		}
		else {
			S.push(std::stoi(token));
		}
	}
	return S.top();
}

int main() {

}

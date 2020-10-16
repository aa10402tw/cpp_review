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

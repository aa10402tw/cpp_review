#include <iostream>
#include <vector>
#include <string>
#include <set>

/* 
IDEA: 
define number of "(" as nl and number of ")" as nr
at each positon, we can insert either "(" or ")"

(nl, nr) +=   
"(" + (nl-1, nr) if nl >= 1
")" + (nl, nr-1) if nr > nl


*/

std::vector<std::string> helper(int n_left, int n_right) {
	if (n_right < n_left || n_right == 0) return {};
	else if (n_right == 1) {
		if (n_left == 0) return { ")" };
		else return { "()" };
	}
	else {
		std::vector<std::string> result;
		if (n_left > 0) {
			std::vector<std::string> subResult_l = helper(n_left - 1, n_right);
			for (auto s : subResult_l)
				result.push_back("(" + s);
		}
		if (n_left < n_right) {
			std::vector<std::string> subResult_r = helper(n_left, n_right - 1);
			for (auto s : subResult_r)
				result.push_back(")" + s);
		}
		return result;
	}
}

std::vector<std::string> generateParenthesis(int n) {
	return helper(n, n);
}

int main() {
	generateParenthesis(3);
}

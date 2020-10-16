#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

bool isPalindrome(std::string s) {
	int left = 0;
	int right = s.size() - 1;
	while (left < right) {
		if (s[left] != s[right]) return false;
		left += 1;
		right -= 1;
	}
	return true;
}

/* Recursive version */
std::vector<std::vector<std::string>> partition(std::string s) {
	std::vector<std::vector<std::string>> result;
	if (s.size() == 0) return result;
	
	for (int len = 1; len <= s.size(); len++) {
		std::string s1 = s.substr(0, len);
		std::string s2 = s.substr(len);
		if (isPalindrome(s1)) {
			if (s1.size() == s.size()) {
				result.push_back({ s1 });
				break;
			}
			std::string prefix = s1;
			std::vector<std::vector<std::string>> postfixs = partition(s2);
			if (postfixs.size() > 0) {
				for (auto postfix : postfixs) {
					std::vector<std::string> part;
					for (auto post : postfix) {
						part.push_back(prefix + post);
					}
					result.push_back(part);
				}
			}
		}
	}
	return result;
}

/* DP version */
std::vector<std::vector<std::string>> partition(std::string s) {
	int N = s.size();
	std::vector<std::vector<std::vector<std::string>>> dp;
	dp.push_back({}); // dp[0] = []

	for (int r = 1; r <= N; r++) {
		std::vector<std::vector<std::string>> parts;
		for (int m = 0; m < r; m++) {
			std::string subs = s.substr(m, r - m); // subs = s[m:r] 
			if (isPalindrome(subs)) {
				if (m == 0) { // subs = s[0:r] 
					parts.push_back({ subs });
				}
				else {
					for (auto pre : dp[m]) { // dp[m] contain all partiton from 0 to m-1 in string s
						std::vector<std::string> part(pre);
						part.push_back(subs);
						parts.push_back(part);
					}
				}

			}
		}
		dp.push_back(parts); // dp[r] contain all partiton from 0 to r-1 in string s
	}
	return dp[N];
}

int main() {

}

/* [Question Description]
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 
The matching should cover the entire input string (not partial).

# Example 1
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

# Example 2
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

# Example 3
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

# Example 4
Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

# Example 5
Input: s = "mississippi", p = "mis*is*p*."
Output: false
*/ 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool isMatch(std::string s, std::string p) {
	/* Using table to keep track of substrings and subpatterns.
	Bottom-up approach is used- starting from the empty string applied on the empty pattern,
	to full string on full pattern string.
	At each stage, we store the boolean value of true or false depending on the match.
	Finally, the output is given by the bottom right element (visually) of the 2d array.
	*/
	const int M = s.size();
	const int N = p.size();

	bool** dp = new bool* [M + 1];
	for (int row = 0; row <= M; row++)
		dp[row] = new bool[N + 1];
	for (int row = 0; row <= M; row++)
		for (int col = 0; col <= N; col++)
			dp[row][col] = false;
	dp[0][0] = true;

	// Lets check for sub-patterns for empty string.        
	for (int j = 1; j <= N; j++)
	{
		if (p[j - 1] == '*') {
			if (j - 1 == 0) return false;
			dp[0][j] = dp[0][j - 2]; // can use zero times
		}
	}

	//Now, let us add traverse the pattern for each possible contiguous sub-string starting from empty string;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			//std::cout << i << ',' << j << ":" << s[i] << p[j] << std::endl;
			if (p[j - 1] == s[i - 1] || p[j - 1] == '.') { // p[j-1] match s[i-1] 
				dp[i][j] = dp[i - 1][j - 1];
			}
			else if (p[j - 1] == '*') { // p[j-1] is star, p[j-2] can use zero or many times
				dp[i][j] = dp[i][j - 2];  // use zero times 
				if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) // use one more time
					dp[i][j] = dp[i][j] | dp[i - 1][j];
			}
			else dp[i][j] = false;
		}
	}
	return dp[M][N];
}
int main() {
	std::cout << isMatch("aab", "c*a*b") << std::endl;
}

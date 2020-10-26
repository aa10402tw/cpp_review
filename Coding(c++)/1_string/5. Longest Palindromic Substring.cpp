#include <iostream>
#include <string>

/*
Given a string s, return the longest palindromic substring in s.
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
*/ 


std::string longestPalindrome(std::string s) {
	int* odd_table = new int[s.size()];
	int* even_table = new int[s.size()];

	// Odd Table
	for (int i = 0; i < s.size(); i++) {
		int j = 1;
		while (true) {
			if (i - j < 0 or i + j >= s.size())
				break;
			if (s.at(i - j) != s.at(i + j))
				break;
			j += 1;
		}
		odd_table[i] = 1 + 2 * (j - 1);
	}
	// Even Table
	for (int i = 0; i < s.size(); i++) {
		int j = 0;
		while (true) {
			if (i - j < 0 or i + j + 1 >= s.size())
				break;
			if (s.at(i - j) != s.at(i + 1 + j))
				break;
			j += 1;
		}
		even_table[i] = 2 + 2 * (j - 1);
	}
	int maxLen = 0;
	std::string ans = "";
	for (int i = 0; i < s.size(); i++) {
		if (odd_table[i] > maxLen) {
			maxLen = odd_table[i];
			int offset = (maxLen - 1) / 2;
			ans = s.substr(i - offset, odd_table[i]);
		}
		if (even_table[i] > maxLen) {
			maxLen = even_table[i];
			int offset = (maxLen - 2) / 2;
			ans = s.substr(i - offset, even_table[i]);
		}
	}
	return ans;
}

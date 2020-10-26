/* [Question Description]
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

# Example 1
Input: haystack = "hello", needle = "ll"
Output: 2

# Example 2
Input: haystack = "aaaaa", needle = "bba"
Output: -1

# Example 3
Input: haystack = "", needle = ""
Output: 0
*/ 
#include <iostream>
#include <string>

/*
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

int strStr(std::string haystack, std::string needle) {
	if (needle.size() == 0) return 0;
	for (int i = 0; i < haystack.size(); i++) {
		if (haystack[i] == needle[0]) {
			std::string str = haystack.substr(i, needle.size());
			if (str == needle)
				return i;
		}
	}
	return -1;
}

int main() {
	std::string haystack = "baabbbbababbbababaaaaaaaaaaabisodiosdosdjfsklksd";
	std::string needle = "jfsk";
	std::cout << strStr(haystack, needle) << std::endl;

	std::cout << ("aaa" == "aaa") << std::endl;
}

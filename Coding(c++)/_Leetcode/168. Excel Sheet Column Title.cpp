/* [Question Description]
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example:

# Example 1
Input: 1
Output: "A"

# Example 2
Input: 28
Output: "AB"

# Example 3
Input: 701
Output: "ZY"
*/ 
#include <iostream>
#include <string>

std::string convertToTitle(int n) {
	std::string s = "";
	while (n > 0) {
		n -= 1;
		s = ((char)('A' + (n % 26))) + s;
		n /= 26;
	}
	return s;
}

int main() {
	std::cout << convertToTitle(1)<< std::endl;
	std::cout << convertToTitle(26) << std::endl;
	std::cout << convertToTitle(27) << std::endl;
	std::cout << convertToTitle(52) << std::endl;
}

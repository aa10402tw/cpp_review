/* [Question Description]
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
Follow up: Could you solve it without converting the integer to a string?

# Example 1
Input: x = 121
Output: true

# Example 2
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

# Example 3
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

# Example 4
Input: x = -101
Output: false
*/ 
#include <iostream>
#include <string>

bool isPalindrome(int x) {
	if (x < 0) return false;
	else if (x < 10) return true;

	std::string digits = "";
	while (x > 0) {
		digits += std::to_string(x % 10);
		x /= 10;
	}

	std::string from_left = "";
	std::string from_right = "";
	for (int i = 0; i < digits.size() / 2; i++) {
		from_left += digits.at(i);
		from_right += digits.at(digits.size()-1-i);
	}
	return from_left == from_right;
}

int main() {

}

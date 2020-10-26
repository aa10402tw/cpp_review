/* [Question Description]
Implement atoi which converts a string to an integer.
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
If no valid conversion could be performed, a zero value is returned.

# Example 1
Input: str = "42"
Output: 42

# Example 2
Input: str = "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign. Then take as many numerical digits as possible, which gets 42.

# Example 3
Input: str = "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

# Example 4
Input: str = "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical digit or a +/- sign. Therefore no valid conversion could be performed.

# Example 5
Input: str = "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer. Thefore INT_MIN (−231) is returned.
*/ 
#include <iostream>
#include <string>


int myAtoi(std::string str) {
	int sign = 1;
	bool digitStart = false;
	std::string digits = "";
	for (int i = 0; i < str.size(); i++) {
		if (!digitStart && str.at(i) == ' ') continue;
		else if (!digitStart && (str.at(i) == '+' || str.at(i) == '-')) {
			digitStart = true;
			if (str.at(i) == '-') sign = -1;
		}
		else if (std::isdigit(str.at(i))) {
			digits += str.at(i);
			digitStart = true;
		}
		else
			break;
	}
	long long result = 0;
	for (int i = 0; i < digits.size(); i++) {
		result *= 10;
		result = result + (long long)(digits.at(i) - '0');
		if (result * sign > INT_MAX) return INT_MAX;
		if (result * sign < INT_MIN) return INT_MIN;
	}
	return (int)(result * sign);
}

int main() {
	std::string str = "-91283472332";
	std::cout << myAtoi(str) << std::endl;
}

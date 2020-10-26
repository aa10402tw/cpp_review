/* [Question Description]
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

# Example 1
Input: num1 = "2", num2 = "3"
Output: "6"

# Example 2
Input: num1 = "123", num2 = "456"
Output: "56088"
*/ 
#include <iostream>
#include <string>

std::string removeLeadingZero(std::string str) {
	int s = 0;
	while (s < str.size() - 1) {
		if (str[s] != '0') break;
		else s += 1;
	}
	return str.substr(s);
}

std::string add(std::string num1, std::string num2) {
	std::string result = "";
	int sum = 0, carry = 0;
	for (int i = 0; i < std::max(num1.size(), num2.size()); i++) {
		int n1 = (i >= num1.size()) ? 0 : (int)(num1.at(num1.size() - 1 - i) - '0');
		int n2 = (i >= num2.size()) ? 0 : (int)(num2.at(num2.size() - 1 - i) - '0');
		sum = n1 + n2 + carry;
		carry = (sum >= 10) ? 1 : 0;
		sum %= 10;
		result = ((char)('0' + sum)) + result;
	}
	if (carry == 1)
		result = "1" + result;
	return removeLeadingZero(result);
}

std::string multiply(std::string num1, std::string num2) {
	std::string result = "0";
	for (int j = 0; j < num2.size(); j++) {
		std::string subresult = "";
		int sum = 0, carry = 0;
		for (int i = 0; i < num1.size(); i++) {
			int n1 = (int)(num1.at(num1.size() - 1 - i) - '0');
			int n2 = (int)(num2.at(num2.size() - 1 - j) - '0');
			sum = n1 * n2 + carry;
			carry = sum / 10;
			sum %= 10;
			subresult = (char)('0' + sum) + subresult;
		}
		if (carry > 0)
			subresult = (char)('0' + carry) + subresult;
		for (int k = 0; k < j; k++)
			subresult += "0";
		result = add(result, subresult);
	}
	return removeLeadingZero(result);
}

int main() {
	std::cout << add("123", "20") << std::endl;
	std::cout << multiply("123", "20") << std::endl;
	std::cout << removeLeadingZero("0000") << std::endl;
}

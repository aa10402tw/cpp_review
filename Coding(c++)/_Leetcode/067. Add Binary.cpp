/* [Question Description]
Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.

# Example 1
Input: a = "11", b = "1"
Output: "100"

# Example 2
Input: a = "1010", b = "1011"
Output: "10101"
*/ 
#include <iostream>
#include <string>
#include <algorithm>


std::string addBinary(std::string a, std::string b) {
	// Add leading zeros
	int N = std::max(a.size(), b.size());
	while (a.size() < N) a = "0" + a;
	while (b.size() < N) b = "0" + b;
	
	std::string result = "";
	int sum = 0;
	int carry = 0;
	for (int i = N - 1; i >= 0; i--) {
		sum = (a.at(i) - '0') + (b.at(i) - '0') + carry;
		carry = 0;
		if (sum >= 2) {
			carry = 1;
			sum %= 2;
		}
		result = std::to_string(sum) + result;
	}
	if (carry == 1) {
		result = "1" + result;
	}
	return result;
}

int main() {
	std::string a = "1";
	std::string b = "111";
	std::cout << addBinary(a, b);
}

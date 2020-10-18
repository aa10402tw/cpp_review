/* [Question Description]
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
Given an integer, convert it to a roman numeral.

# Example 1
Input: num = 3
Output: "III"

# Example 2
Input: num = 4
Output: "IV"

# Example 3
Input: num = 9
Output: "IX"

# Example 4
Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

# Example 5
Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/ 
#include <iostream>
#include <string>

/*

*/ 


std::string intToRoman(int num) {
	int digit_thousand = num / 1000;
	int digit_hundard =  (num % 1000) / 100;
	int digit_ten = (num % 100) / 10;
	int digit_one = (num % 10) / 1;
	std::string s = "";

	for (int i = 0; i < digit_thousand; i++)
		s += "M";

	if(digit_hundard == 9)
		s += "CM";
	else if(digit_hundard ==4)
		s += "CD";
	else {
		if (digit_hundard >= 5)
			s += "D";
		for (int i = 0; i < (digit_hundard %5); i++)
			s += "C";
	}

	if (digit_ten == 9)
		s += "XC";
	else if (digit_ten == 4)
		s += "XL";
	else {
		if (digit_ten >= 5)
			s += "L";
		for (int i = 0; i < (digit_ten % 5); i++)
			s += "X";
	}

	if (digit_one == 9)
		s += "IX";
	else if (digit_one == 4)
		s += "IV";
	else {
		if (digit_one >= 5)
			s += "V";
		for (int i = 0; i < (digit_one % 5); i++)
			s += "I";
	}
	return s;
}

int main() {
	int num = 1994;
	std::cout << intToRoman(num) << std::endl;
}

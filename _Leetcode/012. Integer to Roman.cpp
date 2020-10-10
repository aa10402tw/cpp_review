#include <iostream>
#include <string>

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

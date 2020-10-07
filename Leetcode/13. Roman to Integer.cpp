#include <iostream>
#include <string>

int romanToInt(std::string s) {
	int value = 0;
	for (int i = 0; i < s.size(); i++) {
		// Check Subtraction
		if (i < s.size() - 1) {
			if (s.at(i) == 'I' && (s.at(i + 1) == 'V' || s.at(i + 1) == 'X')) {
				value -= 1;
				i += 1;
			}
			else if (s.at(i) == 'X' && (s.at(i + 1) == 'L' || s.at(i + 1) == 'C')) {
				value -= 10;
				i += 1;
			}
			else if (s.at(i) == 'C' && (s.at(i + 1) == 'D' || s.at(i + 1) == 'M')) {
				value -= 100;
				i += 1;
			}	
		}
		if (s.at(i) == 'I') value += 1;
		if (s.at(i) == 'V') value += 5;
		if (s.at(i) == 'X') value += 10;
		if (s.at(i) == 'L') value += 50;
		if (s.at(i) == 'C') value += 100;
		if (s.at(i) == 'D') value += 500;
		if (s.at(i) == 'M') value += 1000;
	}
	return value;
}

int main() {
	std::string s;
	while (std::cin >> s) {
		std::cout << romanToInt(s) << std::endl;
	}
}

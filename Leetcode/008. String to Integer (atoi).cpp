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

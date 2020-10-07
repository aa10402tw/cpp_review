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

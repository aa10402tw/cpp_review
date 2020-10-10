#include <iostream>
#include <vector>
#include <unordered_map>

int getDigitSS(int num) {
	int SS = 0;
	while (num > 0) {
		int digit = num % 10;
		SS += digit * digit;
		num /= 10;
	}
	return SS;
}

bool isHappy(int n) {
	int num = n;
	std::unordered_map<int, bool> exist;
	while (num != 1 || exist.find(num) == exist.end()) {
		exist[num] = true;
		num = getDigitSS(num);
	}
	return (num == 1);
}

int main() {

}

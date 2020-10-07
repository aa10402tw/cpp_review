#include <iostream>
#include <string>

/*
1. int to string
	std::to_string(x)
	
2. Loop over string 
	for (int i = 0; i < str.size(); i++) {
		char c = str.at(i);
	}
	
3. char to int
	char c = '4';
	int num = c - '0';
	
4. string to int
	int num = stoi(str);
*/


int reverse(int x) {
	long long result = 0;
	bool isNeg = false;
	std::string str = std::to_string(x);
	for (int i = str.size()-1; i>=0; i--) {
		char c = str.at(i);
		if (i == 0 && c == '-') {
			isNeg = true;
		}
		else {
			int digit = c - '0';
			result = result * 10 + digit;
		}
	}
	if (isNeg)
		result *= -1;
	if (result < INT_MIN || result > INT_MAX)
		return 0;
	return (int)result;
}

int main() {
	int num;
	std::cin >> num;
	std::cout << reverse(num) << std::endl;
}

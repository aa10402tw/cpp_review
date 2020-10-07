#include <iostream>
#include <string>

std::string convertToTitle(int n) {
	std::string s = "";
	while (n > 0) {
		n -= 1;
		s = ((char)('A' + (n % 26))) + s;
		n /= 26;
	}
	return s;
}

int main() {
	std::cout << convertToTitle(1)<< std::endl;
	std::cout << convertToTitle(26) << std::endl;
	std::cout << convertToTitle(27) << std::endl;
	std::cout << convertToTitle(52) << std::endl;
}

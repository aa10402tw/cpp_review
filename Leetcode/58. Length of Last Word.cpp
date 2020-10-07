#include <iostream>
#include <string>
#include <sstream>

int lengthOfLastWord(std::string s) {
	std::istringstream iss(s);
	std::string word;
	while (iss >> word);
	return word.size();
}

int main() {
	std::string s = "Hello World";
	std::cout << lengthOfLastWord(s);
}

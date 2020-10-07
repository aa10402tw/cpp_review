#include <iostream>
#include <string>

int strStr(std::string haystack, std::string needle) {
	if (needle.size() == 0) return 0;
	for (int i = 0; i < haystack.size(); i++) {
		if (haystack[i] == needle[0]) {
			std::string str = haystack.substr(i, needle.size());
			if (str == needle)
				return i;
		}
	}
	return -1;
}

int main() {
	std::string haystack = "baabbbbababbbababaaaaaaaaaaabisodiosdosdjfsklksd";
	std::string needle = "jfsk";
	std::cout << strStr(haystack, needle) << std::endl;

	std::cout << ("aaa" == "aaa") << std::endl;
}

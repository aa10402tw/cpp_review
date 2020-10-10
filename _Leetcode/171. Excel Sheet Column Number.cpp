#include <iostream>
#include <string>

int titleToNumber(std::string s) {
	int num = 0;
	int m = 1;
	for (int i = 0; i < s.size(); i++) {
		char c = s[s.size() - 1 - i];
		num += int(c - 'A' + 1) * m;
		if (i < s.size() - 1)
			m *= 26;
	}
	return num;
}

int main() {

}

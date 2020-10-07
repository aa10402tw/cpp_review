#include <iostream>
#include <string>

std::string convert(std::string s, int numRows) {
	if (numRows == 1) return s;

	std::string* lines = new std::string[numRows];
	for (int i = 0; i < numRows; i++) {
		lines[i] = "";
	}
	
	int idx = 0;
	int col = 0;
	while (idx < s.size()) {
		if (col % (numRows - 1) == 0) {
			for (int row = 0; row < numRows; row++) {
				lines[row] += s[idx];
				idx += 1;
				if (idx >= s.size())
					break;
			}
		}
		else {
			int row = numRows-1 - (col%(numRows-1));
			lines[row] += s[idx];
			idx += 1;
		}
		col += 1;
	}

	std::string result = "";
	for (int i = 0; i < numRows; i++) {
		//std::cout << lines[i] << std::endl;
		result += lines[i];
	}
	return result;
}

int main() {
	std::string s = "PAYPALISHIRING";
	std::cout << convert(s, 3);
}

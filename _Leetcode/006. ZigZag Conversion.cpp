/* [Question Description]
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

# Example 1
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

# Example 2
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

# Example 3
Input: s = "A", numRows = 1
Output: "A"
*/ 
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

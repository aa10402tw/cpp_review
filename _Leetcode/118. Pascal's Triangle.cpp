#include <iostream>
#include <vector>

std::vector<std::vector<int>> generate(int numRows) {
	std::vector<std::vector<int>> result;
	for (int row = 0; row < numRows; row++) {
		int numCols = row + 1;
		std::vector<int> rowNums;
		for (int col = 0; col < numCols; col++) {
			if (col == 0 || col == numCols - 1)
				rowNums.push_back(1);
			else
				rowNums.push_back(result[row-1][col-1]+ result[row-1][col]);
		}
		result.push_back(rowNums);
	}
	return result;
}

int main() {
	generate(3);
}

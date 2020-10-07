#include <iostream>
#include <vector>

std::vector<int> getRow(int rowIndex) {
	std::vector<int> oldRow = { 1 };// Row 0
	if (rowIndex == 0) return oldRow;
	for (int i = 1; i <= rowIndex; i++) {
		std::vector<int> newRow;
		for (int j = 0; j < i + 1; j++) {
			if (j == 0 || j == i) newRow.push_back(1);
			else newRow.push_back(oldRow[j-1]+oldRow[j]);
		}
		oldRow = newRow;
	}
	return oldRow;
}

int main() {
	getRow(2);
}

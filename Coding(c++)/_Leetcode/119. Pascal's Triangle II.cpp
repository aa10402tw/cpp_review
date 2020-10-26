/* [Question Description]
Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.
Notice that the row index starts from 0.
In Pascal's triangle, each number is the sum of the two numbers directly above it.
Follow up:
Could you optimize your algorithm to use only O(k) extra space?

# Example 1
Input: rowIndex = 3
Output: [1,3,3,1]

# Example 2
Input: rowIndex = 0
Output: [1]

# Example 3
Input: rowIndex = 1
Output: [1,1]
*/ 
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

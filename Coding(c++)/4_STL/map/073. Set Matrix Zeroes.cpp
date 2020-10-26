/* [Question Description]
Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.
Follow up:

# Example 1
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

# Example 2
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/ 
#include <iostream>
#include <vector>
#include <unordered_map>

/* Time: O(N^2), Space: O(N) */ 
void setZeroes(std::vector<std::vector<int>>& matrix) {
	int M = matrix.size();
	if (M == 0) return;
	int N = matrix[0].size();

	/* Record which rows (cols) are going to set to zero */
	std::unordered_map<int, bool> rowSetToZero;
	std::unordered_map<int, bool> colSetToZero;
	for (int i = 0; i < N; i++)
		rowSetToZero.insert(std::make_pair(i, false));
	for (int j = 0; j < N; j++)
		colSetToZero.insert(std::make_pair(j, false));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] == 0) {
				rowSetToZero[i] = true;
				colSetToZero[j] = true;
			}
		}
	}

	/* Set those rows (cols) to zero */
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (rowSetToZero[i] || colSetToZero[j])
				matrix[i][j] = 0;
		}
	}
}


int main() {

}

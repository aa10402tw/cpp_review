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

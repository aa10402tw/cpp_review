#include <iostream>
#include <vector>
#include <set>

void rotate(std::vector<std::vector<int>>& matrix) {
	int N = matrix.size();

	for (int row = 0; row < N / 2; row++) {
		for (int col = 0; col < (N + 1) / 2; col++) {
			int r1 = row, c1 = col;
			int r2 = col, c2 = N - 1 - row;
			int r3 = N - 1 - row, c3 = N - 1 - col;
			int r4 = N - 1 - col, c4 = row;
			int tmp = matrix[r4][c4];
			matrix[r4][c4] = matrix[r3][c3];
			matrix[r3][c3] = matrix[r2][c2];
			matrix[r2][c2] = matrix[r1][c1];
			matrix[r1][c1] = tmp;
		}
	}
}

int main() {

}

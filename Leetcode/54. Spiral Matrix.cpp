#include <iostream>
#include <vector>

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
	std::vector<int> result;
	int m = matrix.size();
	if (m == 0) return result;
	int n = matrix[0].size();
	int left = 0, right = n - 1, top = 0, down = m - 1;
	int row = 0, col = 0;

	int dir = 0; // right, down, left ,up
	while (result.size() < m * n) {
		if (result.size() == 0) {
			row = 0;
			col = 0;
			if (col == right) {
				dir = 1;
				top += 1;
			}
		}
		else if (dir == 0) {
			col += 1;
			if (col == right) {
				dir = 1;
				top += 1;
			}
		}
		else if (dir == 1) {
			row += 1;
			if (row == down) {
				dir = 2;
				right -= 1;
			}
		}
		else if (dir == 2) {
			col -= 1;
			if (col == left) {
				dir = 3;
				down -= 1;
			}
		}
		else if (dir == 3) {
			row -= 1;
			if (row == top) {
				dir = 0;
				left += 1;
			}
		}
		else {
			return result;
		}
		result.push_back(matrix[row][col]);
	}
	return result;
}

int main() {

}

/* [Question Description]
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

# Example 1
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

# Example 2
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/ 
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

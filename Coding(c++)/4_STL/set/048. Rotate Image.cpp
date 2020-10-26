/* [Question Description]
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

# Example 1
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

# Example 2
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

# Example 3
Input: matrix = [[1]]
Output: [[1]]

# Example 4
Input: matrix = [[1,2],[3,4]]
Output: [[3,1],[4,2]]
*/ 
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

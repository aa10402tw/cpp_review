/* [Question Description]
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

# Example 1
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

# Example 2
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
*/ 
int cvt(char c) {
	if ('0' <= c && c <= '9')
		return c - '0';
	else 
		return -1;
}

bool isValidRow(std::vector<std::vector<char>>& board, int r) {
	bool* exist = new bool[10];
	for (int i = 1; i <= 9; i++)
		exist[i] = false;

	for (int c = 0; c < 9; c++) {
		int num = cvt(board[r][c]);
		if (num != -1) {
			if (exist[num]) return false;
			else exist[num] = true;
		}
	}
	return true;
}

bool isValidCol(std::vector<std::vector<char>>& board, int c) {
	bool* exist = new bool[10];
	for (int i = 1; i <= 9; i++)
		exist[i] = false;

	for (int r = 0; r < 9; r++) {
		int num = cvt(board[r][c]);
		if (num != -1) {
			if (exist[num]) return false;
			else exist[num] = true;
		}
	}
	return true;
}

bool isValidBox(std::vector<std::vector<char>>& board, int R, int C) {
	bool* exist = new bool[10];
	for (int i = 1; i <= 9; i++)
		exist[i] = false;

	for (int r = (R-1)*3; r < R * 3; r++) {
		for (int c = (C - 1) * 3; c < C * 3; c++) {
			int num = cvt(board[r][c]);
			if (num != -1) {
				if (exist[num]) return false;
				else exist[num] = true;
			}
		}
	}
	return true;
}

// Determine if a 9x9 Sudoku board is valid
bool isValidSudoku(std::vector<std::vector<char>>& board) {
    // Check Row
	for (int r = 0; r < 9; r++)
		if (!isValidRow(board, r)) return false;
    // Check Col
	for (int c = 0; c < 9; c++)
		if (!isValidCol(board, c)) return false;
    // Check Box
	for (int R=1; R<=3; R++)
		for (int C = 1; C <= 3; C++)
			if (!isValidBox(board, R, C)) return false;
	return true;
}

int main() {

}

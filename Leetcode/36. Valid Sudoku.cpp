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

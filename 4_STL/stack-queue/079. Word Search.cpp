/* [Question Description]
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

# Example 1
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

# Example 2
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

# Example 3
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
*/ 
#include <iostream>
#include <vector>
#include <string>
#include <stack>

/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, 
where "adjacent" cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Input: board = 
[
	["A","B","C","E"],
	["S","F","C","S"],
	["A","D","E","E"]
], 
word = "ABCCED"
Output: true
*/ 


typedef std::pair<int, int> Pos;

bool DFS(std::vector<std::vector<char>>& board, std::string& word, std::vector<std::vector<bool>>& visited,
	int row, int col, int idx) {

	int M = board.size();
	int N = board[0].size();
	if (row < 0 || row >= M || col < 0 || col >= N) return false;
	else if (board[row][col] != word.at(idx)) return false;
	else if (visited[row][col]) return false;
	else {
		if (idx == word.size() - 1) return true;
		else {
			visited[row][col] = true;
			bool result = (DFS(board, word, visited, row+1, col, idx+1) 
				|| DFS(board, word, visited, row-1, col, idx+1) 
				|| DFS(board, word, visited, row, col+1, idx+1) 
				|| DFS(board, word, visited, row, col-1, idx+1));
			visited[row][col] = false;
			return result;
		}
	}

}

bool solve(std::vector<std::vector<char>>& board, std::string& word, int row, int col) {
	int M = board.size();
	int N = board[0].size();
	std::vector<std::vector<bool>> visited(M, std::vector<bool>(N, false));
	return DFS(board, word, visited, row, col, 0);
}

bool exist(std::vector<std::vector<char>>& board, std::string word) {
	int M = board.size();
	int N = board[0].size();
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == word.at(0) && solve(board, word, i, j)) return true;
		}
	}
	return false;
}

int main() {

}

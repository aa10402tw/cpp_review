#include <iostream>
#include <vector>

/* Solution Idea 
check cell with O is captured along the way and change it's content to .
if captured, fill cell . to X
if not captured, fill cell . to O
*/ 

bool canCapture(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if (board[i][j] != 'O') return true;
        board[i][j] = '.';
        return canCapture(board, i-1, j) && canCapture(board, i+1, j) && canCapture(board, i, j-1) && canCapture(board, i, j+1);
    }
    
void fill(vector<vector<char>>& board, int i, int j, const char f) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
    if (board[i][j] != '.') return;
    board[i][j] = f;
    fill(board, i-1, j, f);
    fill(board, i+1, j, f);
    fill(board, i, j-1, f);
    fill(board, i, j+1, f);
}

void solve(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); ++i)
        for (int j = 0; j < board[0].size(); ++j)
            if (board[i][j] == 'O' && canCapture(board, i, j))
                fill(board, i, j, 'X');
            else
                fill(board, i, j, 'O');
}

int main() {

}

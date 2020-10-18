#include <iostream>
#include <vector>
#include <queue>

void BFS(std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>>& visited, int r, int c) {
	int M = grid.size();
	int N = grid[0].size();
	typedef std::pair<int, int> Pos;
	std::queue<Pos> Q;
	Q.push(std::make_pair(r, c));
	while (!Q.empty()) {
		Pos pos = Q.front();
		Q.pop();
		int row = pos.first;
		int col = pos.second;
		if (row < 0 || row >= M || col < 0 || col >= N) continue;
		if (visited[row][col] || grid[row][col] == '0') continue;
		visited[row][col] = true;
		Q.push(std::make_pair(row+1, col));
		Q.push(std::make_pair(row-1, col));
		Q.push(std::make_pair(row, col+1));
		Q.push(std::make_pair(row, col-1));
	}
}


void DFS(std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>>& visited, int r, int c) {
	int M = grid.size();
	int N = grid[0].size();

	if (r < 0 || r >= M || c < 0 || c >= N) return;
	if (visited[r][c]) return;
	if (grid[r][c] == '0') return;
	visited[r][c] = true;
	DFS(grid, visited, r+1, c);
	DFS(grid, visited, r-1, c);
	DFS(grid, visited, r, c+1);
	DFS(grid, visited, r, c-1);
}

int numIslands(std::vector<std::vector<char>>& grid) {
	int M = grid.size();
	int N = grid[0].size();
	std::vector<std::vector<bool>> visited(M, std::vector<bool>(N, false));

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j] == '1' && visited[i][j] == false) {
				DFS(grid, visited, i, j); // Or BFS 
				cnt += 1;
			}
		}
	}
	return cnt;
}

int main() {

}

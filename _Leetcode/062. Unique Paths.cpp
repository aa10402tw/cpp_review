#include <iostream>


int uniquePaths(int m, int n) {
	int** dp = new int* [m];
	for (int row = 0; row < m; row++) {
		dp[row] = new int[n];
		memset(dp[row], 0, n);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}

int main() {

}

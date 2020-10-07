#include <iostream>

/* Recursive Version */
//int climbStairs(int n) {
//	if (n == 1) return 1; // 1 = 1
//	if (n == 2) return 2; // 2 = 2, 2 = 1 + 1
//	return (climbStairs(n - 1) + climbStairs(n - 2));
//}

/* DP Version */
int climbStairs(int n) {
	if (n == 1) return 1; // 1 = 1
	if (n == 2) return 2; // 2 = 2, 2 = 1 + 1
	int* dp = new int[n+1];
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	return dp[n];
}

int main() {
	std::cout << climbStairs(10) << std::endl;
}

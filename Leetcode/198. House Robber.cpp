#include <iostream>
#include <vector>

/* Recursive solution (slower) */
int helper(std::vector<int>& nums, int s) {
	if (s >= nums.size()) 
		return 0;
	else
		return std::max(
			helper(nums, s + 1), // Not rub i-th
			nums[s] + helper(nums, s + 2)); // rub i-th
}

int rob(std::vector<int>& nums) {
	return helper(nums, 0);
}

/* DP solution (faster) */
int rob(std::vector<int>& nums) {
	int* dp = new int[nums.size()];
	if (nums.size() == 0) return 0;
	else if (nums.size() == 1) return nums[0];
	dp[0] = nums[0];
	dp[1] = std::max(nums[0], nums[1]);
	for (int i = 2; i < nums.size(); i++)
		dp[i] = std::max(
			dp[i-1],
			dp[i-2] + nums[i]
		);
	return dp[nums.size() - 1];
}

int main() {

}

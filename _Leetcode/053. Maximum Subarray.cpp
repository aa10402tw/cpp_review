#include <iostream>
#include <vector>
#include <algorithm>

int maxSubArray(std::vector<int>& nums) {
	int* dp = new int[nums.size()]; // dp[i] is the max sum of array [0...i] if i-th is included.
	dp[0] = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		dp[i] = std::max(nums[i], dp[i - 1] + nums[i]);
	}
	int maxSum = dp[0];
	for (int i = 0; i < nums.size(); i++)
		maxSum = std::max(maxSum, dp[i]);
	return maxSum;
}

int main() {
	std::vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	std::cout << maxSubArray(nums) << std::endl;
}

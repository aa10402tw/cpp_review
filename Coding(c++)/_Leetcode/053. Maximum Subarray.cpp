/* [Question Description]
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

# Example 1
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

# Example 2
Input: nums = [1]
Output: 1

# Example 3
Input: nums = [0]
Output: 0

# Example 4
Input: nums = [-1]
Output: -1

# Example 5
Input: nums = [-2147483647]
Output: -2147483647
*/ 
#include <iostream>
#include <vector>
#include <algorithm>

/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

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

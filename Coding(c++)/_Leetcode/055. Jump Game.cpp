/* [Question Description]
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

# Example 1
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

# Example 2
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
*/ 
#include <iostream>
#include <vector>

bool canJump(std::vector<int>& nums) {
	int N = nums.size();
	bool* dp = new bool[N + 1];
	for (int i = 0; i < N; i++) {
		if (i == 0) dp[i] = true;
		else dp[i] = false;
	}

	for (int i = 0; i < N; i++) {
		if (dp[i] == true) {
			int j = nums[i];
			for (int k = i + 1; k <= i + j; k++) {
				if (k < N) dp[k] = true;
			}
		}
	}
	return dp[N - 1];

}

int main() {
	std::vector<int> nums = { 3,2,1,0,4 };
	std::cout << canJump(nums);
}

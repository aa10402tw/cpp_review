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

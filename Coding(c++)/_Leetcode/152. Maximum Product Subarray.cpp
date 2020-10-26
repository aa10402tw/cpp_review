/* [Question Description]
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

# Example 1
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

# Example 2
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/ 
#include <iostream>
#include <vector>
#include <queue>

int maxProduct(std::vector<int>& nums) {
	int N = nums.size();
	std::vector<int> maxs(N, 0); // maxs[i] store the largest product which last number is nums[i] (i.e., maxs[i] = max (N_j * N_j-1 * ... N_i) for all j <= i)
	std::vector<int> mins(N, 0); // mins[i] store the smallest product which last number is nums[i]
	for (int i = 0; i < nums.size(); i++) {
		if (i == 0) {
			maxs[i] = nums[i];
			mins[i] = nums[i];
		}
		else {
			int maxProd = std::max(maxs[i - 1] * nums[i], mins[i - 1] * nums[i]);
			int minProd = std::min(maxs[i - 1] * nums[i], mins[i - 1] * nums[i]);
			maxs[i] = std::max(nums[i], maxProd);
			mins[i] = std::min(nums[i], minProd);
		}
	}
	int ans = nums[0];
	for (int i = 1; i < N; i++) {
		ans = std::max(ans, maxs[i]);
	}
	return ans;
}

int main() {

}

/* [Question Description]
Given a set of distinct integers, nums, return all possible subsets (the power set).

# Example 1
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/ 
#include <iostream>
#include <vector>

/*
Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
std::vector<std::vector<int>> solve(std::vector<int>& nums, int idx) {
	if (idx == nums.size() - 1) {
		std::vector<std::vector<int>> result = { {nums[idx]}, {} }; // Take or not take
	}
	else {
		std::vector<std::vector<int>> result;
		std::vector<std::vector<int>> subresult = solve(nums, idx + 1);
		for (std::vector<int> subset : subresult) {
			std::vector<int> notTake = subset;
			result.push_back(notTake);
			std::vector<int> take = subset;
			take.push_back(nums[idx]);
			result.push_back(nums);
		}
		return result;
	}
}

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
	if (nums.size() == 0) return {};
	return solve(nums, 0);
}

int main() {

}

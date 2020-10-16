#include <iostream>
#include <vector>

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

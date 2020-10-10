#include <iostream>
#include <vector>
#include <set>

std::vector<std::vector<int>> helper(std::vector<int>& nums, int idx) {
	if (idx > nums.size() - 1)
		return {{}};
	else if (idx == nums.size() - 1) {
		std::vector<int> tuple;
		tuple.assign(nums.begin(), nums.end());
		return { tuple };
	}
	else {
		std::vector<std::vector<int>> result;
		std::set<std::vector<int>> result_set;
		for (int i = idx; i < nums.size(); i++) {
			std::swap(nums[idx], nums[i]);
			std::vector<std::vector<int>> subresult = helper(nums, idx + 1);
			for (auto tuple : subresult) {
				result_set.insert(tuple);
			}
			std::swap(nums[idx], nums[i]);
		}
		for (auto tuple : result_set)
			result.push_back(tuple);
		return result;
	}
}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
	return helper(nums, 0);
}

int main() {

}

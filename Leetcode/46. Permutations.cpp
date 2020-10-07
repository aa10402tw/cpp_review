#include <iostream>
#include <vector>

/* Copy vector 
vec2.assign(vec.begin(), vec.end());
*/

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
		for (int i = idx; i < nums.size(); i++) {
			std::swap(nums[idx], nums[i]);
			std::vector<std::vector<int>> subresult = helper(nums, idx + 1);
			for (auto tuple : subresult)
				result.push_back(tuple);
			std::swap(nums[idx], nums[i]);
		}
		return result;
	}
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
	return helper(nums, 0);
}

int main() {

}

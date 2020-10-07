#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
	std::vector<std::vector<int>> result;
	if (nums.size() < 3) return result;
	std::sort(nums.begin(), nums.end());

	// Remove elements appear more than three times
	std::vector<int> new_nums;
	for (auto v : nums) {
		if (new_nums.size() > 3
			&& v == new_nums[new_nums.size() - 1]
			&& v == new_nums[new_nums.size() - 2]
			&& v == new_nums[new_nums.size() - 3])
			continue;
		else
			new_nums.push_back(v);
	}
	nums = new_nums;

	// Create Map
	std::unordered_map<int, int> v2i;
	std::unordered_map<int, int>::iterator it;
	for (int i = 0; i < nums.size(); i++) {
		v2i[nums[i]] = i;
	}

	// Add valid tuples to set
	std::set<std::vector<int>> result_set;
	for (int i = 0; i < nums.size() - 1; i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			int sum = nums[i] + nums[j];
			it = v2i.find(-sum);
			if (it != v2i.end()) {
				int k = it->second;
				if (k != i && k != j) {
					std::vector<int> tuple = { nums[i], nums[j], nums[k] };
					sort(tuple.begin(), tuple.end());
					result_set.insert(tuple);
				}
			}
		}
	}

	for (auto tuple : result_set) {
		result.push_back(tuple);
	}

	return result;
}

int main() {
	std::vector<int> nums = { 1,2,-3 };
	threeSum(nums);
}

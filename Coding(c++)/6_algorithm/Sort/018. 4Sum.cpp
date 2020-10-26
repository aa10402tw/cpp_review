/* [Question Description]
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
Notice that the solution set must not contain duplicate quadruplets.

# Example 1
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

# Example 2
Input: nums = [], target = 0
Output: []
*/ 
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

/*
IDEA: first record all c+d value in unordered_map (find in O(1))
map[value] = [(ic,id) for all c+d = value]
then for all a+b, find the target-(a+b) value in the map
*/
std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
	std::vector<std::vector<int>> result;
	if (nums.size() < 4) return result;

	std::sort(nums.begin(), nums.end());
	typedef std::pair<int, int> II;
	std::unordered_map<int, std::vector<II>> SIIs; // sum and list of two index
	for (int i = 0; i < nums.size()-1; i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			int sum = nums[i] + nums[j];
			II ii = std::make_pair(i, j);
			SIIs[sum].push_back(ii);
		}
	}
	std::unordered_map<int, std::vector<II>>::iterator it;
	std::set<std::vector<int>> result_set;
	for (int ia = 0; ia < nums.size()-1; ia++) {
		for (int ib = ia+1; ib < nums.size(); ib++) {
			int sum = nums[ia] + nums[ib];
			it = SIIs.find(target - sum);
			if (it != SIIs.end()) {
				std::vector<II> iis = it->second;
				for (auto ii : iis) {
					int ic = ii.first;
					int id = ii.second;
					std::set<int> idx_set = { ia, ib, ic, id };
					if (idx_set.size() == 4) { // Not duplicated
						std::vector<int> tuple = { nums[ia], nums[ib], nums[ic], nums[id] };
						std::sort(tuple.begin(), tuple.end());
						result_set.insert(tuple);
					}
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

}

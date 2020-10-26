/* [Question Description]
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.

# Example 1
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

# Example 2
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
*/ 
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


/* Concate two vectors a and b (to b) 
b.insert(b.end(), a.begin(), a.end());
*/
std::vector<std::vector<int>> helper(std::vector<int>& candidates, int target, int idx) {
	std::vector<std::vector<int>> result;
	std::set<std::vector<int>> result_set;
	if (idx < 0 || target <= 0) 
		return result;
	else {
		int val = candidates[idx];
		int N = target / val;
		for (int i = 0; i <= std::min(1, N); i++) {
			int remain = target - val * i;
			if (remain == 0) {
				std::vector<int> comb(i, val);
				result_set.insert(comb);
				//result.push_back(comb);
			}
			else if (remain > 0) {
				std::vector<std::vector<int>> subresult = helper(candidates, remain, idx - 1);
				if (subresult.size() > 0) {
					for (auto comb : subresult) {
						if (i > 0) {
							std::vector<int> vals(i, val);
							comb.insert(comb.end(), vals.begin(), vals.end());
						}
						result_set.insert(comb);
						//result.push_back(comb);
					}
				}
			}
		}
		for (auto comb : result_set)
			result.push_back(comb);
		return result;
	}
}

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
	std::sort(candidates.begin(), candidates.end());
	return helper(candidates, target, candidates.size() - 1);
}

int main() {
	std::vector<int> a(10, 2);
	std::cout << a.size();
}

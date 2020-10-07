#include <iostream>
#include <vector>
#include <algorithm>


/* Concate two vectors a and b (to b) 
b.insert(b.end(), a.begin(), a.end());
*/
std::vector<std::vector<int>> helper(std::vector<int>& candidates, int target, int idx) {
	std::vector<std::vector<int>> result;
	if (idx < 0 || target <= 0) 
		return result;
	else {
		int val = candidates[idx];
		int N = target / val;
		for (int i = 0; i <= N; i++) {
			int remain = target - val * i;
			if (remain == 0) {
				std::vector<int> comb(i, val);
				result.push_back(comb);
			}
			else if (remain > 0) {
				std::vector<std::vector<int>> subresult = helper(candidates, remain, idx - 1);
				if (subresult.size() > 0) {
					for (auto comb : subresult) {
						if (i > 0) {
							std::vector<int> vals(i, val);
							comb.insert(comb.end(), vals.begin(), vals.end());
						}
						result.push_back(comb);
					}
				}
			}
		}
		return result;
	}
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
	std::sort(candidates.begin(), candidates.end());
	return helper(candidates, target, candidates.size() - 1);
}

int main() {
	std::vector<int> a(10, 2);
	std::cout << a.size();
}

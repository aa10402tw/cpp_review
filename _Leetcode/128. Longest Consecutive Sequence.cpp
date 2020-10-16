#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/* Solution based on sorting, time: O(NlogN), extra space: O(1) 
first sort the numbers, then iterate over numbers
check if nums[i] == nums[i-1] + 1
*/
int longestConsecutive(std::vector<int>& nums) {
	std::sort(nums.begin(), nums.end());
	int ans = 1;
	int cur = 1;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == nums[i - 1]) {
			cur += 1;
			ans = std::max(ans, cur);
		}
		else {
			cur = 1;
		}
	}
	return ans;
}

/* Solution based on hash map, time: O(N), extra space: O(N) 
similar to graph search, each number is a node in graph
and two numbers have edge if abs(n1-n2) == 1

first record all numbers in hash map, 
then for each number in hash map, 
search downward and upward to count the length of consecutive length
(record the visited numbers to avoid repeat search for the same consecutive sequence)
*/
int longestConsecutive(std::vector<int>& nums) {

	std::unordered_map<int, bool> visited;
	for (int num : nums)
		visited[num] = false;

	int ans = 0;
	int cur = 0;
	for (auto n_v : visited) {
		int num = n_v.first;
		if (!visited[num]) {
			cur = 1;
			visited[num] = true;

			int num_down = num - 1;
			while (visited.find(num_down) != visited.end()) {
				visited[num_down] = true;
				cur += 1;
				num_down -= 1;
			}

			int num_up = num + 1;
			while (visited.find(num_up) != visited.end()) {
				visited[num_up] = true;
				cur += 1;
				num_up += 1;
			}

			ans = std::max(ans, cur);
		}
	}

	return ans;
}

int main() {

}

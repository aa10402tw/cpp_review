/* [Question Description]
Given an array, rotate the array to the right by k steps, where k is non-negative.
Follow up:

# Example 1
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

# Example 2
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/ 
#include <iostream>
#include <vector>

/* #1: vector copy, time: O(N), extra space: O(N) */
void rotate(std::vector<int>& nums, int k) {
	if (k >= nums.size()) k = k % nums.size();
	std::vector<int> nums_new;
	for (int i = 0; i < k; i++)
		nums_new.push_back(nums[nums.size() - k + i]);
	for (int i = 0; i < nums.size() - k; i++)
		nums_new.push_back(nums[i]);
	nums = nums_new;
}

/* #2: vector remove from end and insert at start for k times, time: O(N), extra space: O(1) */
void rotate(std::vector<int>& nums, int k) {
	if (k >= nums.size()) k = k % nums.size();
	for (int i = 0; i < k; i++) {
		int num = nums[nums.size() - 1];
		nums.erase(nums.begin() + nums.size() - 1);
		nums.insert(nums.begin(), num);
	}
}

/* #3: vector swap, time: O(N), extra space: O(1) */
void rotate(std::vector<int>& nums, int k) {
	if (k >= nums.size()) k = k % nums.size();
	int start = 0;
	while (start < nums.size() && k > 0) {
		int remain = nums.size() - start - k;
		for (int i = 0; i < k; i++) {
			int j = nums.size() - k + i;
			std::swap(nums[start + i], nums[j]);
		}
		start += k;
		k = k % remain;
	}
}

int main() {

}

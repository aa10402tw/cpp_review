/* [Question Description]
You are given an integer array nums sorted in ascending order, and an integer target.
Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
If target is found in the array return its index, otherwise, return -1.

# Example 1
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

# Example 2
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

# Example 3
Input: nums = [1], target = 0
Output: -1
*/ 
#include <iostream>
#include <vector>
#include <algorithm>


int helper(std::vector<int>& nums, int target, int left, int right) {
	if (left > right) return -1;
	int mid = (left + right) / 2;
	if (target == nums[mid]) return mid;
	else if (nums[left] < nums[right]) { // ascending array, pure binary search
		if (target < nums[mid]) return helper(nums, target, left, mid - 1);
		else return helper(nums, target, mid + 1, right);
	}
	else { // rotated array, two sides need search
		int l = helper(nums, target, left, mid - 1);
		int r = helper(nums, target, mid + 1, right);
		if (l == -1) return r;
		else return l;
	}
}

int search(std::vector<int>& nums, int target) {
	return helper(nums, target, 0, nums.size() - 1);
}

int main() {

}

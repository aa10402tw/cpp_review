/* [Question Description]
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

# Example 1
Input: nums = [1,3,5,6], target = 5
Output: 2

# Example 2
Input: nums = [1,3,5,6], target = 2
Output: 1

# Example 3
Input: nums = [1,3,5,6], target = 7
Output: 4

# Example 4
Input: nums = [1,3,5,6], target = 0
Output: 0

# Example 5
Input: nums = [1], target = 0
Output: 0
*/ 
#include <iostream>
#include <vector>
#include <algorithm>

/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

Input: nums = [1,3,5,6], target = 5
Output: 2
*/

/* Use Binary Search*/
int searchInsert(std::vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	if (target < nums[left]) return 0;
	if (target > nums[right]) return right+1;

	while ( left <= right) {
		int mid = (left + right) / 2;
		if (nums[mid] == target)
			return mid;
		if (mid>0 && nums[mid - 1] < target && target <= nums[mid] )
			return mid;
		if (nums[mid] < target) 
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}


/* use STL: lower_bound() in algorithm*/
//int searchInsert(std::vector<int>& nums, int target) {
//	std::vector<int>::iterator it;
//	it = std::lower_bound(nums.begin(), nums.end(), target);
//	int index = it - nums.begin();
//	return index;
//}

int main() {
	std::vector<int> nums = { 1,3,5,6 };
	int target = 2;
	std::cout << searchInsert(nums, target);
}

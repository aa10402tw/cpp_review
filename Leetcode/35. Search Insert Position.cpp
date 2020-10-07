#include <iostream>
#include <vector>
#include <algorithm>


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

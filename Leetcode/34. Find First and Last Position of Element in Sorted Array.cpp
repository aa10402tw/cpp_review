#include <iostream>
#include <vector>
#include <algorithm>

/* Use binary search to find the start and ending position */
int helper_end(std::vector<int>& nums, int target, int left, int right) {
	if (left > right) return -1;
	int mid = (left + right) / 2;

	if (nums[mid] == target) {
		if (mid + 1 > right || nums[mid + 1] != target) return mid;
		else return helper_end(nums, target, mid + 1, right);
	}
	else if (nums[mid] > target) return helper_end(nums, target, left, mid - 1);
	else return helper_end(nums, target, mid + 1, right);
}

int helper_start(std::vector<int>& nums, int target, int left, int right) {

	if (left > right) return -1;
	int mid = (left + right) / 2;
	if (nums[mid] == target) {
		if (mid - 1 < left || nums[mid - 1] != target) return mid;
		else return helper_start(nums, target, left, mid - 1);
	}
	else if (nums[mid] > target) return helper_start(nums, target, left, mid - 1);
	else return helper_start(nums, target, mid + 1, right);
}

std::vector<int> searchRange(std::vector<int>& nums, int target) {
	return {
		helper_start(nums, target, 0, nums.size() - 1),
		helper_end(nums, target, 0, nums.size() - 1) };
}
int main() {
	std::vector<int> nums = { 5,7,7,8,8,10 };
	int target = 8;
	std::cout << helper_start(nums, target, 0, nums.size() - 1);
}

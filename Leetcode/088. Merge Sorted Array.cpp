#include <iostream>
#include <vector>
#include <algorithm>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
	int i=m-1, j=n-1;
	for (int idx = m + n - 1; idx >= 0; idx--) {
		if (i >=0 && (j<0 || nums1[i] > nums2[j])){
			nums1[idx] = nums1[i];
			i -= 1;
		}
		else {
			nums1[idx] = nums2[j];
			j -= 1;
		}	
	}
}

void printVec(std::vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		std::cout << nums[i];
		if (i < nums.size() - 1)
			std::cout << ",";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> nums1 = { 1,2,3,0,0,0 };
	std::vector<int> nums2 = { 2,5,6 };
	printVec(nums1);

	merge(nums1, 3, nums2, 3);
	printVec(nums1);
}

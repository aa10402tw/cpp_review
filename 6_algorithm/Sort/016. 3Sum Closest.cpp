/* [Question Description]
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

# Example 1
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/ 
#include <iostream>
#include <vector>

int threeSumClosest(std::vector<int>& nums, int target) {
    int ans = nums[0] + nums[1] + nums[2];

    sort(nums.begin(), nums.end());
    for (int idx = 0; idx < nums.size() - 2; idx++) {
        int l = idx + 1, r = nums.size() - 1;
        while (l < r) {
            int threeSum = nums[idx] + nums[l] + nums[r];
            if (std::abs(threeSum - target) < std::abs(ans - target))
                ans = threeSum;
            if (threeSum > target) r--;
            else l++;
        }
    }
    return ans;
}

int main() {
	std::vector<int> nums = { 1,2,-3 };
	threeSumClosest(nums, 2);
}

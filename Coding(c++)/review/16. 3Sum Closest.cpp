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

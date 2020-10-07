#include <iostream>
#include <vector>
#include <algorithm>

void nextPermutation(std::vector<int>& nums) {
    int idx = nums.size() - 2;
    while (idx >= 0) {
    	/* find number nums[idx] from back that is not in desending order (next number going to permute) */
        if (nums[idx] < nums[idx + 1]) {
            int idx2 = idx + 1;
            for (int i = idx + 1; i < nums.size(); i++) {
                if (nums[i] > nums[idx]) idx2 = i;
            }
            // Swap the number nums[idx2] just greater than nums[idx] to be the head
            std::swap(nums[idx], nums[idx2]);
            // Start new permute after the head
            std::sort(nums.begin() + idx + 1, nums.end());
            return;
        }
        else {
            idx -= 1;
        }
    }
    std::sort(nums.begin(), nums.end());
}

int main() {

}

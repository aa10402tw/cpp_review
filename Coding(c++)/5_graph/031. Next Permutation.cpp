/* [Question Description]
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
The replacement must be in place and use only constant extra memory.

# Example 1
Input: nums = [1,2,3]
Output: [1,3,2]

# Example 2
Input: nums = [3,2,1]
Output: [1,2,3]

# Example 3
Input: nums = [1,1,5]
Output: [1,5,1]

# Example 4
Input: nums = [1]
Output: [1]
*/ 
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

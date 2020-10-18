/* [Question Description]
Given an unsorted integer array nums, find the smallest missing positive integer.
Follow up: Could you implement an algorithm that runs in O(n) time and uses constant extra space.?

# Example 1
Input: nums = [1,2,0]
Output: 3

# Example 2
Input: nums = [3,4,-1,1]
Output: 2

# Example 3
Input: nums = [7,8,9,11,12]
Output: 1
*/ 
#include <iostream>
#include <vector>

/*
Given an unsorted integer array nums, find the smallest missing positive integer.
Follow up: Could you implement an algorithm that runs in O(n) time and uses constant extra space.?
*/ 

/* Time: O(N), extra space: O(N)
build a boolean arry to check if number in [1.....N+1] exist or not
(N number store in [1...N+1], there must be at least one missing value) 
*/
int firstMissingPositive(std::vector<int>& nums) {
    int N = nums.size();
    if (N == 0) return 1;
    std::vector<bool> exist(N+2, false);
    for (auto num:nums)
        if (num >=1 && num <= N+1) exist[num] = true;
    for (int i=1; i<=N+1; i++)
        if (!exist[i]) return i;
    return -1;
}


/* Solution based on swap, Time: O(N), extra space: O(1)
Swap the numbers to correct position (num-1) if 1 <= number <= N,
then check which positon don't have correct number 

e.g.,
input : [1,4,5,2]
after swap : [1,2,5,4]
return : 3 (since postion 2 don't have the correct number 3)
*/
void solve_swap(vector<int>& nums, int src, int dst) {
    if (nums[src] == nums[dst]) return;
    int N = nums.size();
    std::swap(nums[src], nums[dst]);
    if (nums[src] >= 1 && nums[src] <= N && nums[src] != src+1) {
        dst = nums[src] - 1;
        solve_swap(nums, src, dst);
    }
}

int firstMissingPositive(vector<int>& nums) {
    int N = nums.size();
    if (N == 0) return 1;
    
    for (int i=0; i<N; i++) {
        if (nums[i] >= 1 && nums[i] <= N && nums[i] != i+1) {
            int src = i;
            int dst = nums[i] - 1;
            solve_swap(nums, src, dst);
        }
    }
    for (int i=0; i<N; i++)
        if (nums[i] != i+1) return i+1;
    return N+1;
}

/* [Question Description]
A peak element is an element that is greater than its neighbors.
Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that nums[-1] = nums[n] = -∞.
Follow up: Your solution should be in logarithmic complexity.

# Example 1
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

# Example 2
Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.
*/ 
#include <iostream>
#include <vector>

/* 
The solution is based on binary search.

For each iteration, we search in the range [L, R], with the following properties
L: (nums[L-1] < nums[L])
R: (nums[R] > nums[R+1])
(first iteration is okay because nums[-1] = nums[N] = -infinity)

At each iteration, we set M = (L+R)/2, then compare M with right neighbor M+1
if (nums[M] < nums[M+1]) -> search [M+1, R] (because M+1 satisify properties of L)
if (nums[M] > nums[M+1]) -> search [L, M] (because M satisify properties of R)

Termination condition:
L == R, and since (nums[L-1] < nums[L]) and (nums[R] > nums[R+1]), L is the peak.
*/ 
int solve(std::vector<int>& nums, int left, int right) {
    if(left == right) return left; // Termination condition
    int mid = (left + right) / 2;
    if (nums[mid] > nums[mid+1]) return solve(nums, left, mid); // search [L,M]
    else return solve(nums, mid+1, right); // search [M+1,R]
}

int findPeakElement(std::vector<int>& nums) {
    return solve(nums, 0, nums.size()-1); // search [0, N-1]
}

/* Iterative version */
int findPeakElement(vector<int>& nums) {
    int low=0,high=nums.size()-1;
    while(low<high){
        int mid=(low+high)/2;
        if(nums[mid]>nums[mid+1]) high=mid;
        else low=mid+1;
    }
    return low;
}

int main() {

}

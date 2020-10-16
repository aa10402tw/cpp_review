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

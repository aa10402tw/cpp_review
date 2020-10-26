#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


/* Sort take O(NlogN) */
int solve(std::vector<int>& nums, int left, int right, int k) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size()-k];
}

/* Use partition in QuickSort */
int partition(std::vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (nums[j] < pivot) {
            i += 1;
            std::swap(nums[i], nums[j]);
        }
    }
    i += 1;
    std::swap(nums[i], nums[right]);
    return i;
}

/* T(N) = O(N) + T(N/2) = O(N) + O(N/2) + .... = O(N) */
int solve2(std::vector<int>& nums, int left, int right, int k) {
    int p = partition(nums, left, right);
    if (p == right-k+1) return nums[p];
    else if (p < right-k+1) return solve2(nums, p+1, right, k);
    else return solve2(nums, left, p-1, k-(right-p)-1);
}

int findKthLargest(vector<int>& nums, int k) {
	//return solve(nums, 0, nums.size()-1, k);
    return solve2(nums, 0, nums.size()-1, k);
}

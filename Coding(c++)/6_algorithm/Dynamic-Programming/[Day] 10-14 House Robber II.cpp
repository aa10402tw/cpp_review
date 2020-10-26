#include <iostream>
#include <vector>

int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return std::max(0, nums[0]);
    if (nums.size() == 2) return std::max(0, std::max(nums[0], nums[1]));
    
    /* Two Dynammic Programming */
    int N = nums.size();
    std::vector<int> dp1(N, 0);
    std::vector<int> dp2(N, 0);
    for (int i=0; i<N-1; i++) {
        if (i==0) dp1[i] = nums[i];
        else if (i==1) dp1[i] = std::max(nums[i-1], nums[i]);
        else dp1[i] = std::max(dp1[i-1], dp1[i-2]+nums[i]);
    }
    for (int i=1; i<N; i++) {
        if (i==1) dp2[i] = nums[i];
        else if (i==2) dp2[i] = std::max(nums[i-1], nums[i]);
        else dp2[i] = std::max(dp2[i-1], dp2[i-2]+nums[i]);
    }
    return std::max(dp1[N-2], dp2[N-1]);

}

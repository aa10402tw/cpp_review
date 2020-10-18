/* [Question Description]
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.
Note: Please solve it without division and in O(n).
Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

# Example 1
Input:  [1,2,3,4]
Output: [24,12,8,6]
*/ 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/* Soulution Idea 
Two pass, 
first pass from left to right, store product of a_1...a_k-1 in k position
second pass from right to left, make up the remaining part

e.g., [a1, a2, a3, a4, a5]
first pass -> [1, a1, a1*a2, a1*a2*a3, a1*a2*a3*a4]
second pass remaining part 	
	  1           a5      a5*a4 	a5*a4*a3 	a5*a4*a3*a2					
[a1*a2*a3*a4,  a1*a2*a3,  a1*a2,       a1,           1     ]

final result: [a2*a3*a4*a5, a1*a3*a4*a5, a1*a2*a4*a5, a1*a2*a3*a5, a1*a2*a3*a4]
*/ 
vector<int> productExceptSelf(vector<int>& nums) {
    int N = nums.size();
    vector<int> result(N, 1);
    for (int i=1; i<N; i++) {
        result[i] = result[i-1] * nums[i-1];
    }
    int left = 1;
    for (int i=N-1; i>=0; i--) {
        result[i] *= left;
        left *= nums[i];
    }
    return result;
}

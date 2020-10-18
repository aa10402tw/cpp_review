/* [Question Description]
Shuffle a set of numbers without duplicates.
*/ 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/* Soulution
1. get random number 
	srand (time(NULL));
	int j = rand() % (i+1); // get number between [0,i]
	
2. To shuffle an array a of n elements (indices 0..n-1):
	for i from n - 1 downto 1 do
		j = random integer with 0 <= j <= i
		exchange a[j] and a[i]
*/ 
class Solution {
private:
    std::vector<int> nums;

public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return this->nums;
        srand (time(NULL)); /* initialize random seed: */
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        std::vector<int> new_nums = nums;
        
        for (int i=new_nums.size()-1; i>=1; i--) {
            int j = rand() % (i+1);
            std::swap(new_nums[i], new_nums[j]);
        }
        return new_nums;
        
    }
};

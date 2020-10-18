/* [Question Description]
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory?

# Example 1
Input: nums = [2,2,1]
Output: 1

# Example 2
Input: nums = [4,1,2,1,2]
Output: 4

# Example 3
Input: nums = [1]
Output: 1
*/ 
#include <iostream>
#include <unordered_map>
#include <vector>

/* Map solution, record each value's count in map*/
int singleNumber_map(std::vector<int>& nums) {
	std::unordered_map<int, int> v2c;
	for (auto num : nums) {
		if (v2c.find(num) == v2c.end())
			v2c[num] = 1;
		else
			v2c[num] += 1;
	}
	for (auto vc : v2c) {
		if (vc.second == 1)
			return vc.first;
	}
	return -1;
}

/* XOR solution, XOR all number, the result will be the number that appear once */
int singleNumber_xor(std::vector<int>& nums) {
	int N = nums.size();
	int result = 0;
	int i;

	for (i = 0; i < N; i++)
	{ // XOR all the elements, the one appearing once will survive
		result ^= nums[i];
	}
	return result;
}

int main() {

}

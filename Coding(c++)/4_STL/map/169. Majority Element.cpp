/* [Question Description]
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.

# Example 1
Input: [3,2,3]
Output: 3

# Example 2
Input: [2,2,1,1,1,2,2]
Output: 2
*/ 
#include <iostream>
#include <vector>
#include <unordered_map>

/* Map solution, time: O(N), space: O(N) */
int majorityElement(std::vector<int>& nums) {
	std::unordered_map<int, int> v2c; // <value, count>
	for (auto num : nums) {
		if (v2c.find(num) == v2c.end())
			v2c[num] = 1;
		else
			v2c[num] += 1;

		if (v2c[num] > nums.size() / 2)
			return num;
	}

	for (auto vc : v2c)
		if (vc.second > nums.size() / 2)
			return vc.first;

	return -1;
}

int main() {

}

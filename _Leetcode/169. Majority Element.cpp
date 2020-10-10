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

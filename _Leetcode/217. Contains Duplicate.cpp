#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

bool containsDuplicate(std::vector<int>& nums) {
	std::unordered_map<int, bool> exist;
	for (auto num : nums) {
		if (exist.find(num) == exist.end())
			exist[num] = true;
		else
			return true;
	}
	return false;
}

int main() {

}

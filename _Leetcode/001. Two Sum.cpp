#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

// Brute-force Solution (O^2)
/*
std::vector<int> twoSum(std::vector<int>& nums, int target) {
	std::vector<int> idxs;
	for (int i = 0; i < nums.size()-1; i++) {
		for (int j = i+1; j < nums.size(); j++) {
			if (nums[i] + nums[j] == target) {
				idxs.push_back(i);
				idxs.push_back(j);
				break;
			}
		}
	}
	return idxs;
}
*/

// One Pass with map (O)
std::vector<int> twoSum(std::vector<int>& nums, int target) {
	std::vector<int> idxs;
	std::map<int, int> v2i; // map <value, index>
	std::map<int, int>::iterator it;
	for (int i = 0; i < nums.size(); i++) {
		it = v2i.find(target - nums[i]);
		if (it != v2i.end()) {
			idxs.push_back(it->second);
			idxs.push_back(i);
			break;
		}
		else {
			v2i.insert(std::pair<int, int>(nums[i], i));
		}
	}
	return idxs;
}

int main() {
	std::string line;
	getline(std::cin, line);
	std::istringstream iss(line);
	int num, target;
	std::vector<int> nums;
	while (iss >> num) {
		nums.push_back(num);
	}
	std::cin >> target;
	std::vector<int> idxs = twoSum(nums, target);
	std::cout << idxs[0] << "," << idxs[1] << std::endl;
}

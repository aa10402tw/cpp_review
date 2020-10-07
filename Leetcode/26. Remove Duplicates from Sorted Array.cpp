#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// erase the 6th element
// myvector.erase(myvector.begin() + 5);

int removeDuplicates(std::vector<int>& nums) {
	int i = 1;
	while (i < nums.size()) {
		if (nums[i] == nums[i - 1])
			nums.erase(nums.begin() + i);
		else
			i += 1;
	}
	return nums.size();
}

int main() {
	int num;
	std::vector<int> nums;
	std::string line;
	getline(std::cin, line);
	std::istringstream iss(line);
	while (iss >> num) {
		nums.push_back(num);
	}
	std::cout << removeDuplicates(nums) << std::endl;
}

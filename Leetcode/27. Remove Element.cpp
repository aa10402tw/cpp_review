#include <iostream>
#include <algorithm>    // std::swap
#include <vector>
#include <string>
#include <sstream>

// erase the 6th element
// myvector.erase(myvector.begin() + 5);
// faster way: swap element to the back 
 

int removeElement(std::vector<int>& nums, int val) {
	int last = nums.size() - 1;
	int i = 0;
	while (i <= last) {
		if (nums[i] == val) {
			std::swap(nums[i], nums[last]);
			last -= 1;
		}
		else {
			i += 1;
		}
	}
	return last + 1;
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
	std::cout << removeElement(nums, 3) << std::endl;
}

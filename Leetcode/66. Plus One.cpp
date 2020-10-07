#include <iostream>
#include <vector>

/* 
std::vector.insert()
	iterator insert (const_iterator position, const value_type& val);
	e.g., myvector.insert (myvector.begin(), 200);
*/ 

void printVec(std::vector<int> &nums) {
	for (int i = 0; i < nums.size(); i++) {
		std::cout << nums[i];
	}
}

std::vector<int> plusOne(std::vector<int>& digits) {
	std::vector<int> results;
	int sum = 0;
	int carry = 1;
	for (int i = digits.size() - 1; i >= 0; i--) {
		sum = digits[i] + carry;
		carry = 0;
		if (sum >= 10) {
			carry = 1;
			sum %= 10;
		}
		results.insert(results.begin(), sum);
	}
	if (carry == 1)
		results.insert(results.begin(), 1);
	return results;
}

int main() {
	std::vector<int> digits = { 1,2,9 };
	printVec(digits);

	digits = plusOne(digits);
	printVec(digits);
}

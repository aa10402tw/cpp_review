/* [Question Description]
Given a non-empty array of digits representing a non-negative integer, increment one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.

# Example 1
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

# Example 2
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

# Example 3
Input: digits = [0]
Output: [1]
*/ 
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

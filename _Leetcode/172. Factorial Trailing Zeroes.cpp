/* [Question Description]
Given an integer n, return the number of trailing zeroes in n!.
Follow up: Could you write a solution that works in logarithmic time complexity?

# Example 1
Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.

# Example 2
Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.

# Example 3
Input: n = 0
Output: 0
*/ 
#include <iostream>
#include <string>


/* 
1. 0 = 2x5 
2. n! = n x (n-1) x (n-2) x ....
*/

int numOfFactor(int num, int k) {
	int cnt = 0;
	while (num > 0 && num % k == 0) {
		num /= k;
		cnt += 1;
	}
	return cnt;
}

int trailingZeroes(int n) {
	int numOfFive = 0;
	int numOfTwo = 0;
	for (int i = 2; i <= n; i++) {
		numOfTwo += numOfFactor(i, 2);
		numOfFive += numOfFactor(i, 5);
	}
	return std::min(numOfFive, numOfTwo);
}

int main() {

}

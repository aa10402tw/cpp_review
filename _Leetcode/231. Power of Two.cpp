/* [Question Description]
Given an integer n, write a function to determine if it is a power of two.

# Example 1
Input: n = 1
Output: true
Explanation: 20 = 1

# Example 2
Input: n = 16
Output: true
Explanation: 24 = 16

# Example 3
Input: n = 3
Output: false

# Example 4
Input: n = 4
Output: true

# Example 5
Input: n = 5
Output: false
*/ 
#include <iostream>

bool isPowerOfTwo(int n) {
	if (n <= 0) return false;
	else if (n == 1 || n == 2) return true;
	else if (n % 2 != 0) return false;
	else return isPowerOfTwo(n / 2);
}

int main() {

}

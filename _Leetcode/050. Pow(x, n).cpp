/* [Question Description]
Implement pow(x, n), which calculates x raised to the power n (i.e. xn).

# Example 1
Input: x = 2.00000, n = 10
Output: 1024.00000

# Example 2
Input: x = 2.10000, n = 3
Output: 9.26100

# Example 3
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/ 
#include <iostream>

double helper(double x, long long N) {
	double ans = x;
	long long i = 1;
	if (N <= 3) {
		while (i < N) {
			ans = ans * x;
			i = i + 1;
		}
		return ans;
	}
	else {
		while (i * 2 < N) {
			ans = ans * ans;
			i = i + i;
		}
		long j = N - i;
		if (j > 0)
			ans = ans * helper(x, j);
		return ans;
	}
}

double myPow(double x, int n) {
	if (x == 0 || x == 1) return x;
	if (n == 0) return 1;
	if (n == 1) return x;
	long long N = n;
	
	if (N < 0) {
		N = std::abs(N);
		x = 1 / x;
	}
	double ans = helper(x, N);
	return ans;
}

int main() {
	std::cout << myPow(2, -2147483648) << std::endl;
}

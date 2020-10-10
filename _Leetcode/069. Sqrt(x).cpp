#include <iostream>

// Can speed up with binary search, but be careful to deal with overflow when compute mid*mid
int mySqrt(int x) {
	long long X = x;
	long long ans = 0;
	while (ans * ans < X) {
		if ((ans + 1) * (ans + 1) > X)
			break;
		else
			ans += 1;
	}
	return ans;
}

int main() {
	int x = 8;
	std::cout << mySqrt(2147395599);
}

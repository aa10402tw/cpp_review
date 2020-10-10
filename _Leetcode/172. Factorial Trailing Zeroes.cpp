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

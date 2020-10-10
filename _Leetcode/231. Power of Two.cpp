#include <iostream>

bool isPowerOfTwo(int n) {
	if (n <= 0) return false;
	else if (n == 1 || n == 2) return true;
	else if (n % 2 != 0) return false;
	else return isPowerOfTwo(n / 2);
}

int main() {

}

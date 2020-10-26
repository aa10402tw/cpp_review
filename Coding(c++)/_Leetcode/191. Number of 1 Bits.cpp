/* [Question Description]
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
Note:
Follow up: If this function is called many times, how would you optimize it?

# Example 1
Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

# Example 2
Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.

# Example 3
Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
*/ 
#include <iostream>
#include <bitset>
#include <string>


/* C++ bitset usage
1. Bit Representation Class
	1 in set of 4 bit (from lowest digit to high digit) = {1, 0, 0, 0}
	in bitset = [0,0,0,1] (from high to low)

2. Constructing Bitset
Constuct 01: 8 bits initialized to zero
	bitset<8> bitset1;
Construct 02: Construct it from a integer number
	bitset<8> bitset2(177);
Construct 03: Construct it from string
	bitset<8> bitset3(string("11111100"));

3. Setting and Resetting Bits
// reset:0, set:1, flip:0->1 or 1->0
bitset2.reset(); cout << bitset2 << endl;
bitset2.set(4); cout << bitset2 << endl;
bitset3.set();	cout << bitset3 << endl;
bitset3.reset(1); cout << bitset3 << endl;

4. Testing the State of Bit
bitset.test(i) return true if i-th bit is true

5. Convert to int or string
mybit_int = (int)(mybit.to_ulong());
mybit_string = mybit.to_string();
*/

int hammingWeight(uint32_t n) {
	int cnt = 0;
	std::bitset<32> b(n);
	for (int i = 0; i < 32; i++)
		if (b.test(i)) cnt += 1;
	return cnt;
}

int main() {

}

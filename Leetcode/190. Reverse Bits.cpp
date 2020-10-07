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

uint32_t reverseBits(uint32_t n) {
	std::bitset<32> b(n);
	std::bitset<32> b_r(0);
	for (int i = 0; i < 32; i++) {
		if (b.test(i))
			b_r.set(32 - 1 - i);
		else
			b_r.reset(32 - 1 - i);
	}
	return (int)(b_r.to_ulong());
}

int main() {
	std::bitset<8> bitset3(1);
	std::cout << "Constructor with string parameter.Content of bitset3: "
		<< bitset3 << std::endl;
}

/* [Question Description]
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.
If the last word does not exist, return 0.

# Example 1
Input: "Hello World"
Output: 5
*/ 
#include <iostream>
#include <string>
#include <sstream>

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word (last word means the last appearing word if we loop from left to right) in the string.
If the last word does not exist, return 0.
Note: A word is defined as a maximal substring consisting of non-space characters only.

Input: "Hello World"
Output: 5
*/ 

int lengthOfLastWord(std::string s) {
	std::istringstream iss(s);
	std::string word;
	while (iss >> word);
	return word.size();
}

int main() {
	std::string s = "Hello World";
	std::cout << lengthOfLastWord(s);
}

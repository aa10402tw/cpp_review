/* [Question Description]
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
Note:
You may assume both s and t have the same length.

# Example 1
Input: s = "egg", t = "add"
Output: true

# Example 2
Input: s = "foo", t = "bar"
Output: false

# Example 3
Input: s = "paper", t = "title"
Output: true
*/ 
#include <iostream>
#include <string>
#include <unordered_map>

bool isIsomorphic(std::string s, std::string t) {
	if (s.size() != t.size()) return false;
	std::unordered_map<char, char> s2t;
	std::unordered_map<char, char> t2s;
	for (int i = 0; i < s.size(); i++) {
		char c1 = s.at(i);
		char c2 = t.at(i);
		if (s != t) {
			if (s2t.find(c1) == s2t.end() && t2s.find(c2) == t2s.end()) {
				s2t[c1] = c2;
				t2s[c2] = c1;
			}
			else if (s2t.find(c1) != s2t.end() && t2s.find(c2) != t2s.end()) {
				if (s2t[c1] != c2) return false;
				if (t2s[c2] != c1) return false;
			}
			else {
				return false;
			}
		}
	}
	return true;
}


int main() {

}

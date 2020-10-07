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

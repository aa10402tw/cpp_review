#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

std::string longestCommonPrefix(std::vector<std::string>& strs) {
	std::string prefix = "";
	if(strs.size() == 0)
		return prefix;
	int minLen= strs[0].size();
	for (int i = 1; i < strs.size(); i++) {
		minLen = (strs[i].size() < minLen) ? strs[i].size() : minLen;
	}
	for (int j = 0; j < minLen; j++) {
		char c = strs[0].at(j);
		for (int i = 1; i < strs.size(); i++) {
			if (c != strs[i].at(j))
				return prefix;
		}
		prefix += c;
	}
	return prefix;
}

int main() {
	std::string line;
	std::string str;
	getline(std::cin, line);
	std::istringstream iss (line);
	std::vector<std::string> strs;
	while (iss >> str) {
		strs.push_back(str);
	}
	std::cout << longestCommonPrefix(strs) << std::endl;


}

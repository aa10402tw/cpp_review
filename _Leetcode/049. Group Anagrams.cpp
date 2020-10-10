#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>


std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
	std::unordered_map<std::string, std::vector<std::string>> s2vs;
	for (auto str : strs) {
		std::string key = str + "";
		sort(str.begin(), str.end());
		if (s2vs.find(key) == s2vs.end()) {
			s2vs[key] = { str };
		}
		else {
			std::vector<std::string> vs = s2vs[key];
			vs.push_back(str);
			s2vs[key] = vs;
		}
	}

	std::vector<std::vector<std::string>> result;
	for (auto s_vs : s2vs) {
		result.push_back(s_vs.second);
	}
	return result;
}

int main() {
	std::vector<std::string> vs = { "eat","tea","tan","ate","nat","bat" };
	std::vector<std::vector<std::string>> result = groupAnagrams(vs);
	for (auto _vs : result) 
		for (auto s : _vs)
			std::cout << s << std::endl;
}

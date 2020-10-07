#include <iostream>
#include <vector>
#include <string>
#include <map>



std::vector<std::string> helper(std::string digits, int idx, std::map<std::string, std::string>& d2cs) {
	

	std::vector<std::string> result;
	if (idx >= digits.size()) return result;
	result = helper(digits, idx + 1, d2cs);

	char c = digits.at(idx);
	std::string d;
	d = c;
	std::string cs = d2cs[d];
	if (result.size() == 0) {
		for (auto c : cs) {
			d = c;
			result.push_back(d);
		}
	}
	else {
		std::vector<std::string> new_result;
		for (auto c : cs) 
			for (auto s : result) {
				d = c;
				new_result.push_back(d + s);
			}
		result = new_result;
	}
	return result;
}

std::vector<std::string> letterCombinations(std::string digits) {
	std::map<std::string, std::string> d2cs;
	d2cs["2"] = "abc";
	d2cs["3"] = "def";
	d2cs["4"] = "ghi";
	d2cs["5"] = "jkl";
	d2cs["6"] = "mno";
	d2cs["7"] = "pqrs";
	d2cs["8"] = "tuv";
	d2cs["9"] = "wxyz";
	return helper(digits, 0, d2cs);
}


int main() {
	std::vector<std::string> result = letterCombinations("23");
	for(auto s:result)
		std::cout << s << std::endl;
}

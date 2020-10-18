/* [Question Description]
Given a list of non-negative integers nums, arrange them such that they form the largest number.

# Example 1
Input: nums = [10,2]
Output: "210"

# Example 2
Input: nums = [3,30,34,5,9]
Output: "9534330"

# Example 3
Input: nums = [1]
Output: "1"

# Example 4
Input: nums = [10]
Output: "10"
*/ 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


/* Solution 
covert the nums to strings, and sort the strings 
then concate all strings
*/ 
static bool cmp(std::string s1, std::string s2) { 
	int N = std::min(s1.size(), s2.size());
	for (int i = 0; i < N; i++) {
        if (s1.at(i) > s2.at(i)) return true;
        if (s2.at(i) > s1.at(i)) return false;
    }
    if (s1.size() == s2.size()) return true;
    else return cmp(s1+s2, s2+s1); 
}

std::string largestNumber(std::vector<int>& nums) {
	
	/* Turn nums to strings (remove repeated nums and record count) */
	std::vector<std::string> numStrs;
	std::unordered_map<std::string, int> strCount;
	for (int num : nums) {
		std::string s = std::to_string(num);
		if (strCount.find(s) == strCount.end()) {
            strCount[s] = 1;
            numStrs.push_back(s);
        }
        else{
        	strCount[s] += 1;
		}
	}
	
	/* Sort the strings */
	std::sort(numStrs.begin(), numStrs.end(), cmp);
	
	/* Concate the strings */
	std::string result = "";
	for (std::string s : numStrs) {
        int cnt = strCount[s];
        for (int i=0; i<cnt; i++)
            result += s;
    }
	
	/* Remove leading zeros */
    int numleadingZero = 0;
    for (int i=0; i<result.size()-1; i++) {
        if (result[i] == '0') numleadingZero += 1;
        else break;
    }
    result = result.substr(numleadingZero);
	return result;
}

#include <iostream>
#include <vector>
#include <unordered_map>

/*
All DNA is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T', for example: "ACGAATTCCG". 
When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
*/ 

std::vector<std::string> findRepeatedDnaSequences(std::string s) {
	std::vector<std::string> result;
	std::unordered_map<std::string, int> strCnt;
	for (int i=9; i<s.size(); i++) {
	    std::string subs = s.substr(i-9, 10);
	    if (strCnt.find(subs) == strCnt.end()) {
	        strCnt[subs] = 1;
	    }
	    else {
	        if (strCnt[subs] == 1) result.push_back(subs);
	        strCnt[subs] += 1;
	    }
	}
	return result;
}

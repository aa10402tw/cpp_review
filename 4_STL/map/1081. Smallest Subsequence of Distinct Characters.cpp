/* [Question Description]
Return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

# Example 1
Input: s = "bcabc"
Output: "abc"

# Example 2
Input: s = "cbacdcbc"
Output: "acdb"
*/ 
#include <iostream>
#include <string>
#include <unordered_map> 
#include <stack>

/* Soulution Idea
Similar to [Monotonic Stack] (a stack that the elmemnt from bottom to top is an monotonic sequence)
that is, when ever we met a new element, we compare new element with the top of Stack
if the top is smaller than new element, we direclty push the element to the stack
if the top is greater than new element, we pop out top element, and keeping doing this until

we keep a stack to be *almost* monotoic, except for the following conditons
1. if the stack already have this char, we ignore the new char (since we need string with no duplicate)
2. if the char if the last one in the origin string, we must push it to stack (since we have to use all character)  

so, we keep a hash map[char_count] to record the number of occurence left for a character,
and keep a hash map[existed] to record whether a character is already appear in stack,
then iterate over the origin string
if the stack already have the character (existed[c] == true), ignore it 
else if the stack is empty, push the character to stack
else we pop top elements of stack, if the new character smaller than top elements and those top element still appear in the following string (char_count[c] > 0)
	
e.g., cbaadcbc, stack change as follow 
 c   b   a   c   d   c   b   c
						|b| |b|
			    |d| |d| |d| |d|
            |a| |a| |a| |a| |a|
|c| |b| |a| |c| |c| |c| |c| |c|
*/

std::string smallestSubsequence(std::string s) {
    std::unordered_map <char, int> char_count;
    std::unordered_map <char, bool> existed;
    for (auto c : s) {
        if (char_count.find(c) == char_count.end())
            char_count[c] = 1;
        else 
            char_count[c] += 1;
        existed[c] = false;
    }
    
    std::stack<char> S;
    for (int i=0; i<s.size(); i++) {
        char c = s[i];
        char_count[c] -= 1;
        if (!existed[c]) {
            while (!S.empty()) {
                char top_c = S.top();
                if (c < top_c && char_count[top_c] > 0) {
                    S.pop();
                    existed[top_c] = false;
                }
                else{
                    break;
                }
            }
            S.push(c);
            existed[c] = true;
        }
    }
    std::string result = "";
    while(!S.empty()) {
        char c = S.top();
        S.pop();
        result = c + result;
    }
    return result;
}

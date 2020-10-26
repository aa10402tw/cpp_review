/* [Question Description]
Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

# Example 1
Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.

# Example 2
Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/ 
#include <iostream>
#include <vector>
#include <queue>
#include <string>

class Solution {
private:
    std::string s;
    int K;
    std::vector<std::vector<int>> freqs;
public:
    int solve(int start, int end) {
        if (start > end || (end - start + 1) < K) return 0;

        std::vector<int> invalidIdxs;
        for (int i = start; i <= end; i++) {
            int idx = s.at(i) - 'a';
            /* freq_c is the frequency of c at s[start:end+1] 
	            freqs[start][c] store frequency of c in s[0:start]
	            freqs[end][c] store frequency of c in s[0:end]
	            so freq_c = frequency of c in s[start:end+1] = freqs[end+1][c] - freqs[start][c]
            */
            int freq_c = freqs[end + 1][idx] - freqs[start][idx];
            if (freq_c < K) {
                invalidIdxs.push_back(i);
            }
        }
        if (invalidIdxs.size() == 0) return end - start + 1;
        else {
            int maxSize = 0;
            for (int i = 0; i < invalidIdxs.size(); i++) {
                if (i == 0) {
                    maxSize = std::max(maxSize, solve(start, invalidIdxs[i] - 1));
                }
                else {
                    maxSize = std::max(maxSize,
                        solve(invalidIdxs[i - 1] + 1, invalidIdxs[i] - 1));
                }
                if (i == invalidIdxs.size() - 1) {
                    maxSize = std::max(maxSize,
                        solve(invalidIdxs[i] + 1, end));
                }
            }
            return maxSize;
        }
    }

    int longestSubstring(std::string s, int k) {
        int N = s.size();
        this->s = s;
        this->K = k;

        /* freqs[i] stores frequency of char c in s[0:i] */
        freqs = std::vector<std::vector<int>>(N + 1, std::vector<int>(26, 0));
        for (int i = 1; i < N + 1; i++) {
            freqs[i] = freqs[i - 1];
            int idx = s.at(i - 1) - 'a';
            freqs[i][idx] = freqs[i][idx] + 1;
        }

        return solve(0, N - 1);
    }
};

int main() {

}

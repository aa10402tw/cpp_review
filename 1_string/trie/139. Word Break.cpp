#include <iostream>
#include <vector>
#include <unordered_set> 

struct TrieNode{
    std::vector<TrieNode*> children;
    bool isWord;
    TrieNode() {
        isWord = false;
        children = vector<TrieNode*>(26, nullptr);
    }
};

class Trie{
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(std::string s) {
        int N = s.size();
        TrieNode* p = root;
        for (int i=0; i<N; i++) {
            int idx = s.at(i) - 'a';
            if (p->children[idx] == nullptr)
                p->children[idx] = new TrieNode();
            p = p->children[idx];
        }
        p->isWord = true;
    }
};
    
/* Trie + Hash set (avoid repeated traversal) */
bool solve(std::string s, Trie& trie) {
    int N = s.size();
    TrieNode* p = trie.root;
    
    /* Use hash map to avoid repeated traversal */
    std::unordered_set<TrieNode*> srcs;
    srcs.insert(trie.root);
    
    for (int i=0; i<N; i++) {
        int idx = s.at(i) - 'a';
        std::unordered_set<TrieNode*> dsts;
        for (TrieNode* p: srcs) {
            if (p->children[idx] != nullptr) {
                dsts.insert(p->children[idx]);
                if (p->children[idx]->isWord) 
                    dsts.insert(trie.root);
            }
        }
        srcs = dsts;
    }
    for (TrieNode* p: srcs) { 
        if (p->isWord) return true;
    }
    return false;     
}

/* Pure DP */
bool solve2(std::string s, std::vector<string>& wordDict) {
	int N = s.size();
	
	// Covert vector to hash map
    std::unordered_set<std::string> words;
    for (std::string word:wordDict)
        words.insert(word);
        
    // DP[i] : is string s[0:i] can be break into words in wordDict?
    std::vector<bool> dp(N+1, false); 
    dp[0] = true;
    // Split string into s[0:j] and s[j:i]
	// dp[i] = true if "s[0:j] can be break" (dp[j] == true) and "s[j:i] is in dict"
    for (int i=0; i<N+1; i++) {
        for (int j=0; j<i; j++) {
            int len = i-j;
            if (dp[j] && (words.find(s.substr(j, len)) != words.end()) ) { 
                dp[i] = true;
                break;
            }
        }
    }
    return dp[N];
}
    
bool wordBreak(std::string s, std::vector<string>& wordDict) {
    Trie trie;
    for (std::string s:wordDict) {
        trie.insert(s);
    }
    return solve(s, trie);
}
    
int main() {

}

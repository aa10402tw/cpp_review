class Trie {
    
    struct TrieNode {
        std::vector<TrieNode*> children;
        bool isWord;
        TrieNode(): isWord(false), children(std::vector<TrieNode*>(26, nullptr)) {};
    };
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(std::string word) {
        int N = word.size();
        TrieNode* cur = root;
        for (int i=0; i<N; i++) {
            int idx = word.at(i) - 'a';
            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int N = word.size();
        TrieNode* cur = root;
        for (int i=0; i<N; i++) {
            int idx = word.at(i) - 'a';
            if (cur->children[idx] == nullptr) {
                return false;
            }
            cur = cur->children[idx];
        }
        return cur != nullptr && cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int N = prefix.size();
        TrieNode* cur = root;
        for (int i=0; i<N; i++) {
            int idx = prefix.at(i) - 'a';
            if (cur->children[idx] == nullptr) {
                return false;
            }
            cur = cur->children[idx];
        }
        return cur != nullptr;
    }
};


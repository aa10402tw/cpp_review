/* [Question Description]
Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.
The encoded string should be as compact as possible.

# Example 1
Input: root = [2,1,3]
Output: [2,1,3]

# Example 2
Input: root = []
Output: []
*/ 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue> 
#include <sstream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::string serialize(TreeNode* root) {
    if (root == nullptr)
        return " null";
    else
        return " " + std::to_string(root->val) + serialize(root->left) + serialize(root->right);
}


TreeNode* buildBST(std::istringstream& iss) {
    std::string s;
    iss >> s;
    if (s == "null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(s));
    root->left = buildBST(iss);
    root->right = buildBST(iss);
    return root;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(std::string data) {
    std::istringstream iss(data);
    return buildBST(iss);
}
int main() {
    TreeNode* root = deserialize("2 1 3 1 2 3");
    std::cout << serialize(root) << std::endl;
}

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

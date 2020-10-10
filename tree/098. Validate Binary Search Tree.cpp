#include <iostream>
#include <vector>
#include <queue> 


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode* root, long long low, long long high) {
    if (root == nullptr)
        return true;
    else if (root->val <= low || root->val >= high)
        return false;
    else
        return helper(root->left, low, std::min(high, (long long)root->val)) && helper(root->right, std::max(low, (long long)root->val), high);
}

bool isValidBST(TreeNode* root) {
    long long low = (long long)INT_MIN - 1;
    long long high = (long long)INT_MAX + 1;
    return helper(root, low, high);
}

int main() {

}

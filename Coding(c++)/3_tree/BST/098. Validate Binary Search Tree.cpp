/* [Question Description]
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:

# Example 1
    2
   / \
  1   3

Input: [2,1,3]
Output: true

# Example 2
    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/ 
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

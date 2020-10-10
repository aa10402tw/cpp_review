#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* helper(
    std::vector<int>& preorder, std::vector<int>& inorder, 
    int s1, int e1, int s2, int e2) {
    if (s1 > e1 || s2 > e2) return nullptr;
    int val = preorder[s1];
    TreeNode* root = new TreeNode(val);
    if (s1 == e1) return root;
    std::vector<int>::iterator it = std::find(
        inorder.begin() + s2, inorder.begin() + e2, val);
    int idx = std::distance(inorder.begin(), it);
    int NL = idx - s2;
    root->left = helper(preorder, inorder, s1+1, s1+NL, s2, idx-1);
    root->right = helper(preorder, inorder, s1+NL+1, e1, idx+1, e2);
    return root;
}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    int N = preorder.size();
    return helper(preorder, inorder, 0, N - 1, 0, N - 1);
}    

int main() {

}

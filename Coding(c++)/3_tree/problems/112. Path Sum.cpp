/* [Question Description]
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
Note: A leaf is a node with no children.
Given the below binary tree and sum = 22,
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/ 
#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode* root, int sum) {
	if (root == nullptr) 
		return false;
	else if (root->left == nullptr && root->right == nullptr)
		return root->val == sum;
	else 
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

int main() {

}

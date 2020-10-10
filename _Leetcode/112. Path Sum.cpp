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

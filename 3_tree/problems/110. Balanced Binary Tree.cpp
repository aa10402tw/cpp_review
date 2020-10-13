#include <iostream>
#include <vector>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int treeHeight(TreeNode* root) {
	if (root == nullptr) return 0;
	else return std::max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

bool isBalanced(TreeNode* root) {
	if (root == nullptr) return true;
	else if (std::abs(treeHeight(root->left) - treeHeight(root->right)) > 1) return false;
	else return isBalanced(root->left) && isBalanced(root->right);
}

int main() {

}

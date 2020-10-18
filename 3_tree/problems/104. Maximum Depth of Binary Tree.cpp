/* [Question Description]
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Note: A leaf is a node with no children.
Given binary tree [3,9,20,null,null,15,7],
return its depth = 3.
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

int maxDepth(TreeNode* root) {
	if (root == nullptr) return 0;
	return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main() {

}

/* [Question Description]
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

# Example 1
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

# Example 2
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

# Example 3
Input: root = [2,1], p = 2, q = 1
Output: 2
*/ 
#include <iostream>
#include <vector>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::vector<TreeNode*> FindPathToNode(TreeNode* root, TreeNode* p) {
	std::vector<TreeNode*> path;
	while (root != p) {
		path.push_back(root);
		if (p->val < root->val)  root = root->left;
		else root = root->right;
	}
	path.push_back(p);
	return path;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	std::vector<TreeNode*> path_p = FindPathToNode(root, p);
	std::vector<TreeNode*> path_q = FindPathToNode(root, q);
	TreeNode* lca = root;
	for (int i = 0; i < std::min(path_p.size(), path_q.size()); i++) {
		if (path_p[i] != path_q[i]) break;
		else lca = path_p[i];
	}
	return lca;
}


int main() {

}

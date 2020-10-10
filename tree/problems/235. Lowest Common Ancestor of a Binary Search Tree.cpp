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

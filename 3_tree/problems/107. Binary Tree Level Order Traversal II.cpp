/* [Question Description]
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
For example:
Given binary tree [3,9,20,null,null,15,7],

return its bottom-up level order traversal as:
*/ 
#include <iostream>
#include <queue>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

typedef std::pair<int, TreeNode*>LTN; // Level and TreeNode
std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
	std::vector<std::vector<int>> levels;
	if (root == nullptr) return levels;

	std::queue<LTN> q;
	q.push(std::make_pair(0, root));
	while (!q.empty()) {
		LTN ltn = q.front();
		q.pop();
		int l = ltn.first;
		TreeNode* tn = ltn.second;
		if (l >= levels.size()) {
			std::vector<int> level;
			levels.push_back(level);
		}
		levels[l].push_back(tn->val);
		if (tn->left != nullptr) q.push(std::make_pair(l + 1, tn->left));
		if (tn->right != nullptr) q.push(std::make_pair(l + 1, tn->right));
	}
	std::vector<std::vector<int>> levels_bottom;
	for (int l = levels.size() - 1; l >= 0; l--)
		levels_bottom.push_back(levels[l]);
	return levels_bottom;

}

int main() {

}

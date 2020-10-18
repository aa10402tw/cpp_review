/* [Question Description]
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 
But the following [1,2,2,null,3,null,3] is not:
 
Follow up: Solve it both recursively and iteratively.
*/ 
#include <iostream>
#include <string>
#include <queue>
#include <vector>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(std::vector<int>& nums) {
	std::queue<TreeNode*> q;

	TreeNode* root = new TreeNode(nums[0]);
	q.push(root);
	int idx = 1;
	while (idx < nums.size()) {
		TreeNode* cur = q.front();
		q.pop();

		if (cur == nullptr) continue;

		TreeNode* left = (nums[idx] == -1) ? nullptr: new TreeNode(nums[idx]);
		cur->left = left;
		q.push(left);
		idx += 1;

		if (idx >= nums.size()) break;
		TreeNode* right = (nums[idx] == -1) ? nullptr : new TreeNode(nums[idx]);
		cur->right = right;
		q.push(right);
		idx += 1;
	}
	return root;
}

bool helper(TreeNode* tn1, TreeNode* tn2) {
	if (tn1 == nullptr && tn2 == nullptr) return true;
	else if (tn1 == nullptr || tn2 == nullptr) return false;
	else {
		if (tn1->val != tn2->val) return false;
		return helper(tn1->left, tn2->right) && helper(tn1->right, tn2->left);
	}
}

bool isSymmetric(TreeNode* root) {
	if (root == nullptr) return true;
	return helper(root->left, root->right);
}

int main() {
	std::vector<int> nums = { 1,2,2,2,-1,2 };
	TreeNode* root = buildTree(nums);
}

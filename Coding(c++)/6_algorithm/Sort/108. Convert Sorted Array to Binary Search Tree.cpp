/* [Question Description]
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/ 
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

TreeNode* getBSTRoot(std::vector<int>& nums, int left, int right) {
	if (left > right) return nullptr;
	int mid = (left + right) / 2;
	TreeNode* root = new TreeNode(nums[mid]);
	root->left = getBSTRoot(nums, left, mid - 1);
	root->right = getBSTRoot(nums, mid+1, right);
	return root;
}

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
	return getBSTRoot(nums, 0, nums.size() - 1);
}

int main() {

}

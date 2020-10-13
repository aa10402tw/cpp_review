#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct MyTreeNode {
	int val;
	int maxLeftPath;
	int maxRightPath;
	MyTreeNode* left;
	MyTreeNode* right;
	MyTreeNode() : val(0), left(nullptr), right(nullptr), maxLeftPath(0), maxRightPath(0){}
	MyTreeNode(int x, MyTreeNode* left, MyTreeNode* right, int leftSum, int rightSum) : 
		val(x), left(left), right(right), maxLeftPath(leftSum), maxRightPath(rightSum) {}
};

MyTreeNode* buildTree(TreeNode* root) {
	if (root == nullptr) return nullptr;
	MyTreeNode* myRoot = new MyTreeNode();
	myRoot->val = root->val;
	myRoot->left = buildTree(root->left);
	myRoot->right = buildTree(root->right);
	myRoot->maxLeftPath = 0;
	if (myRoot->left != nullptr) {
		myRoot->maxLeftPath = std::max(myRoot->maxLeftPath, myRoot->left->val + myRoot->left->maxLeftPath);
		myRoot->maxLeftPath = std::max(myRoot->maxLeftPath, myRoot->left->val + myRoot->left->maxRightPath);
	}
	myRoot->maxRightPath = 0;
	if (myRoot->right != nullptr) {
		myRoot->maxRightPath = std::max(myRoot->maxRightPath, myRoot->right->val + myRoot->right->maxLeftPath);
		myRoot->maxRightPath = std::max(myRoot->maxRightPath, myRoot->right->val + myRoot->right->maxRightPath);
	}
	return myRoot;
}

int findMaxSum(MyTreeNode* myRoot) {
	if (myRoot == nullptr) return INT_MIN;
	int maxPath = std::max(myRoot->val, myRoot->maxLeftPath + myRoot->val + myRoot->maxRightPath);
	maxPath = std::max(maxPath, findMaxSum(myRoot->left));
	maxPath = std::max(maxPath, findMaxSum(myRoot->right));
	return maxPath;
}

int maxPathSum(TreeNode* root) {
	MyTreeNode* myRoot = buildTree(root);
	return findMaxSum(myRoot);
}

int main() {

}

/*

      8
 (7)/   \(10)
   2     3
  / \   / \
 5   1 2   7
 
 MaxPathSum for node eight is (maxLeftPath + node_val + maxRightSum) (7+8+10)
 
 */

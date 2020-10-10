#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/* 
Because tree is an recursive structure,
so most of the tree problem can be solved by recusive approach
*/
bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == nullptr && q == nullptr) return true;
	else if(p == nullptr || q == nullptr) return false;
	else {
		if (p->val != q->val) return false;
		else return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
}

int main() {
	
}

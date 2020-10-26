#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


/* Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: 
¡§The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants 
(where we allow a node to be a descendant of itself).¡¨
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
*/

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



/* Solution Idea
if both left and right match -> must be the LCA, return root
return node that match either of two nodes (might contain LCA)
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr) return nullptr;
	if (root == p || root == q) return root; 
    
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if(left!=nullptr && right!=nullptr) return root;
    else if(left!=nullptr) return left;
    else if(right!=nullptr) return right;
    else return nullptr;
}

/* Solution Idea
First list the ancestor of both nodes, then from root travese unitl the last equal node
*/
std::vector<TreeNode*> getAncestors(TreeNode* root, TreeNode* p) {
    if (root == nullptr) return {};
    else if (root == p) return {p};
    else {
        std::vector<TreeNode*> leftResult = getAncestors(root->left, p);
        if (leftResult.size() > 0) {
            leftResult.push_back(root);
            return leftResult;
        }
        std::vector<TreeNode*> rightResult = getAncestors(root->right, p);
        if (rightResult.size() > 0) {
            rightResult.push_back(root);
            return rightResult;
        }
        return {};
    }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    std::vector<TreeNode*> pAnc = getAncestors(root, p);
    std::reverse(pAnc.begin(), pAnc.end());
    std::vector<TreeNode*> qAnc = getAncestors(root, q);
    std::reverse(qAnc.begin(), qAnc.end());
    TreeNode* lca = root;
    for (int i=1; i<std::min(pAnc.size(), qAnc.size()); i++)
         if (pAnc[i] == qAnc[i]) lca = pAnc[i];
    return lca;
}


/* [Question Description]
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

# Example 1
Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1

# Example 2
Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
*/ 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


/* Given a binary search tree, write a function kthSmallest to find the kth smallest element in it. 
Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
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
Inorder Traversal of BST is an sorted numbers
*/
void inorder(TreeNode* root, std::vector<int>& result) {
    if (root != nullptr) {
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
}

int kthSmallest(TreeNode* root, int k) {
    std::vector<int> result;
    inorder(root, result);
    return result[k-1];
}

/* Solution Idea
First compute number of nodes in subtree for each node
then for each node t, if its left child have K nodes in subtree
we know t is the (K+1)-smallest element in tree
if target == (K+1) return t.val
if target > (K+1) find (target-(k+1)) in right subtree
if target < (K+1) find target in left subtree
*/
class Solution {
private:
    std::unordered_map<TreeNode*, int> map; // num of nodes in subtree
public:
    int computeNumOfNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int result = 1;
        result += computeNumOfNodes(root->left);
        result += computeNumOfNodes(root->right);
        map[root] = result;
        return result;
    }
    int solve(TreeNode* root, int k) {
        int kth = map[root->left] + 1;
        if (kth == k) return root->val;
        else if (kth < k) return solve(root->right, k-kth);
        else return solve(root->left, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        map = std::unordered_map<TreeNode*, int>();
        map[nullptr] = 0;
        computeNumOfNodes(root);
        return solve(root, k);
    }
};

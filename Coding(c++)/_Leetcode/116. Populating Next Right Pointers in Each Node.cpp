/* [Question Description]
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
 
Follow up:

# Example 1
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
*/ 
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/*
           1
      2          3
   4    5     6     7
  8 9 10 11 12 13 14 15

*/
void solve(Node* left, Node* right) {
    if (left == nullptr || right == nullptr) return;
    left->next = right;
    solve(left->left, left->right);
    solve(right->left, right->right);
    while (left->right != nullptr) {
        left->right->next = right->left;
        left = left->right;
        right = right->left;
    }
}

Node* connect(Node* root) {
    if (root != nullptr)
        solve(root->left, root->right);
    return root;
}

int main() {

}

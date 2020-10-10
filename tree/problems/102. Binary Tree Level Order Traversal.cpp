#include <iostream>
#include <vector>
#include <queue> 


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> result;
    if (root == nullptr) return result;
    typedef std::pair<TreeNode*, int> data;
    std::queue<data> Q;
    Q.push(std::make_pair(root, 0));
    while (!Q.empty()) {
        std::pair<TreeNode*, int> data = Q.front();
        Q.pop();
        TreeNode* node = data.first;
        int level = data.second;
        if (level >= result.size()) {
            std::vector<int> vec;
            result.push_back(vec);
        }
        result[level].push_back(node->val);
        if (node->left != nullptr) Q.push(std::make_pair(node->left, level + 1));
        if (node->right != nullptr) Q.push(std::make_pair(node->right, level + 1));
    }
    return result;
}

int main() {

}

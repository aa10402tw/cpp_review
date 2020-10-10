Table of Contents
=================
  * [Traversal](#Traversal)

## Traversal
For example, a tree <br/>
   2 <br/>
 /   \ <br/>
1     3
#### Preorder-Traversal (VLR)
```
void preorder(TreeNode* root, std::vector<int>& result) { // VLR: 213
    if (root != nullptr) {
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }
}
```

#### Inorder-Traversal (LVR)
```
void inorder(TreeNode* root, std::vector<int>& result) { // LVR: 123
    if (root != nullptr) {
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
}
```

#### Postorder-Traversal (LRV)
```
void inorder(TreeNode* root, std::vector<int>& result) { // LRV: 132
    if (root != nullptr) {
        postorder(root->left, result);
        result.push_back(root->val);
        postorder(root->right, result);
    }
}
```

#### Levelorder-Traversal
```
std::vector<std::vector<int>> levelOrder(TreeNode* root) { // [[1], [2,3]]
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
```



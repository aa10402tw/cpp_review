Table of Contents
=================
  * [Traversal](#Traversal)

## Traversal
For example, a tree
    2
  /   \
 1     3
#### Preorder-Traversal (VLR)
preorder result: 213
```
void preorder(TreeNode* root, std::vector<int>& result) { // VLR
    if (root != nullptr) {
      result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }
}
```

#### Inorder-Traversal (LVR)
inorder result: 123
```
void inorder(TreeNode* root, std::vector<int>& result) { // LVR
    if (root != nullptr) {
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
}
```

#### Postorder-Traversal (LRV)
postorder result: 132
```
void inorder(TreeNode* root, std::vector<int>& result) { // LRV
    if (root != nullptr) {
        postorder(root->left, result);
        result.push_back(root->val);
        postorder(root->right, result);
    }
}
```



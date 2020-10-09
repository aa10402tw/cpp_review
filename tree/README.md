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



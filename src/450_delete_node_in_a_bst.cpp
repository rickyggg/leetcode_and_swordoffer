class Solution {
public:
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root)
      return root;
    TreeNode *tmp;
    if (key < root->val) {
      root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
      root->right = deleteNode(root->right, key);
    } else if (key == root->val) {
      if (root->left && root->right) {
        tmp = FindMin(root->right);
        root->val = tmp->val;
        root->right = deleteNode(root->right, root->val);
      } else {
        tmp = root;
        if (root->left == nullptr)
          root = root->right;
        else
          root = root->left;
        delete tmp;
      }
    }
    return root;
  }
  TreeNode *FindMin(TreeNode *root) {
    if (root)
      while (root->left != nullptr)
        root = root->left;
    return root;
  }
};

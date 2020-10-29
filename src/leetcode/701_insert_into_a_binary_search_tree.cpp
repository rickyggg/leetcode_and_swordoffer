class Solution {
public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (!root) {
      TreeNode *tmp = new TreeNode(val);
      return tmp;
    }
    if (root->val > val)
      root->left = insertIntoBST(root->left, val);
    else
      root->right = insertIntoBST(root->right, val);
    return root;
  }
};

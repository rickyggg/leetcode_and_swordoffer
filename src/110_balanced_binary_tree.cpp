class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if (root == nullptr)
      return true;
    if ((Height(root->left) - Height(root->right)) < -1 ||
        (Height(root->left) - Height(root->right)) > 1)
      return false;
    else
      return isBalanced(root->left) && isBalanced(root->right);
  }
  int Height(TreeNode *root) {
    if (root == nullptr)
      return 0;
    else
      return max(Height(root->left), Height(root->right)) + 1;
  }
};

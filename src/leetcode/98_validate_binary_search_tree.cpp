class Solution {
public:
  bool Valid(TreeNode *root, long min_val, long max_val) {
    if (!root)
      return true;
    if (root->val <= min_val || root->val >= max_val)
      return false;
    return Valid(root->left, min_val, root->val) &&
           Valid(root->right, root->val, max_val);
  }
  bool isValidBST(TreeNode *root) { return Valid(root, LONG_MIN, LONG_MAX); }
};

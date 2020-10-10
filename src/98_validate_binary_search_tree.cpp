class Solution {
public:
  bool Valid(TreeNode *root, TreeNode *min_node, TreeNode *max_node) {
    if (!root)
      return true;
    if (min_node && root->val <= min_node->val ||
        max_node && root->val >= max_node->val)
      return false;
    return Valid(root->left, min_node, root) &&
           Valid(root->right, root, max_node);
  }
  bool isValidBST(TreeNode *root) { return Valid(root, nullptr, nullptr); }
};

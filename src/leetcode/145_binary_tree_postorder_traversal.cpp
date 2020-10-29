class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    if (root == nullptr)
      return {};
    Traversal(root);
    return res;
  }
  void Traversal(TreeNode *root) {
    if (root) {
      Traversal(root->left);
      Traversal(root->right);
      res.push_back(root->val);
    }
    return;
  }

private:
  vector<int> res;
};

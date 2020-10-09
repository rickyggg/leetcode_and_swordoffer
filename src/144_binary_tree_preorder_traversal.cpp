class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    if (root == nullptr)
      return {};
    Traversal(root);
    return res;
  }
  void Traversal(TreeNode *root) {
    if (root) {
      res.push_back(root->val);
      Traversal(root->left);
      Traversal(root->right);
    }
    return;
  }

private:
  vector<int> res;
};

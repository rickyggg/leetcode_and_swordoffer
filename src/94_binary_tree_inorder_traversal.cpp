class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    if (root == nullptr)
      return {};
    Traversal(root);
    return res;
  }
  void Traversal(TreeNode *root) {
    if (root) {
      Traversal(root->left);
      res.push_back(root->val);
      Traversal(root->right);
    }
    return;
  }
private:
    vector<int> res;
};

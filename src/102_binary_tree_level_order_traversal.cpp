class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr)
      return {};
    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
      res.push_back({});
      int level_size = q.size();
      for (int i = 0; i < level_size; ++i) {
        TreeNode *tmp = q.front();
        q.pop();
        res[level].push_back(tmp->val);
        if (tmp->left)
          q.push(tmp->left);
        if (tmp->right)
          q.push(tmp->right);
      }
      ++level;
    }
    return res;
  }
};

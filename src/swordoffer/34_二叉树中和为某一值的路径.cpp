/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<vector<int> > res;
    vector<int> temp;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return {};
        backtrack(root, sum);
        return res;
    }
    void backtrack(TreeNode *root, int sum) {
        if (!root) return;
        temp.push_back(root->val);
        sum -= root->val;
        if (sum == 0 && !root->left && !root->right)
            res.push_back(temp);
        backtrack(root->left, sum); // 左
        backtrack(root->right, sum); // 右
        temp.pop_back(); // 函数退出之前先弹出当前节点
    }
};

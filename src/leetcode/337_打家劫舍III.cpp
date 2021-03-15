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
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return max(pick[root], not_pick[root]);
    }

private:
    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        dfs(root->left);
        dfs(root->right);
        pick[root] = root->val + not_pick[root->left] + not_pick[root->right];
        not_pick[root] = max(pick[root->left], not_pick[root->left]) + max(pick[root->right], not_pick[root->right]);
    }
    unordered_map<TreeNode*, int> pick, not_pick;
};
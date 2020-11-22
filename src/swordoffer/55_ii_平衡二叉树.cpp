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
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return traverse(root, depth);
    }
    bool traverse(TreeNode* root, int& depth) {
        if (!root) {
            depth = 0;
            return true;
        }
        int left, right;
        if(traverse(root->left, left) && traverse(root->right, right)) {
            int diff = left - right;
            if (diff >= -1 && diff <= 1) {
                depth = max(left, right) + 1;
                return true;
            }
        }
        return false;
    }
};

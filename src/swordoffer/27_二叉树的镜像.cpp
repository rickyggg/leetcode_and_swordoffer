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
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) return nullptr;
        swap(root->left,root->right);
        if (root->left)
            mirrorTree(root->left);
        if (root->right)
            mirrorTree(root->right);
        return root;
    }
};

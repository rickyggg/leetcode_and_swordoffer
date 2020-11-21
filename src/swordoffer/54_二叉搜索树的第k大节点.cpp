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
    int kthLargest(TreeNode* root, int k) {
        traverse(root, k);
        return res;    
    }
private:
    int res = 0;
    void traverse(TreeNode* root, int &k) {
        if (!root) return;
        traverse(root->right, k);
        if (--k == 0)
            res = root->val;
        if (k > 0)
            traverse(root->left, k);
        return;
    }
};

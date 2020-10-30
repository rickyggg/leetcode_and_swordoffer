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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0) return nullptr;
        return recursionBuild(preorder.begin(), inorder.begin(), inorder.end());
    }
    TreeNode* recursionBuild(vector<int>::iterator pre_left,
                             vector<int>::iterator in_left,
                             vector<int>::iterator in_right) {
        if (in_right == in_left) return nullptr;
        TreeNode* root = new TreeNode(*pre_left);
        auto root_in = find(in_left, in_right, *pre_left);
        root->left = recursionBuild(pre_left + 1, in_left, root_in);
        root->right = recursionBuild(pre_left + 1 + (root_in - in_left),                                                      root_in + 1, in_right);
        return root;
    }
};

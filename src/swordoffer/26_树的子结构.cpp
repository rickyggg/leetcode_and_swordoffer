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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        bool res = false;
        if (A && B) {
            if (A->val == B->val)
                res = FindSubTree(A, B);
            if (!res)
                res = isSubStructure(A->left, B);
            if (!res)
                res = isSubStructure(A->right, B);
        }
        return res;
    }
    bool FindSubTree(TreeNode* A, TreeNode* B) {
        if (!B) return true;
        if (!A) return false;
        if (A->val != B->val) return false;
        return FindSubTree(A->left, B->left) && FindSubTree(A->right, B->right);

};

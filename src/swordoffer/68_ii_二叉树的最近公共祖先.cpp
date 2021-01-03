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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return nullptr;
        vector<TreeNode*> path_p, path_q;
        GetNodePath(root, p, path_p);
        GetNodePath(root, q, path_q);
        return GetLastCommonNode(path_p, path_q);
    }
    bool GetNodePath(TreeNode* root, TreeNode* p_node, vector<TreeNode*> &path) {
        if (!root) return false;
        path.push_back(root);
        if (root == p_node) return true;
        bool found = GetNodePath(root->left, p_node, path) || 
                    GetNodePath(root->right, p_node, path);
        if (!found)
            path.pop_back();
        return found;
    }
    TreeNode* GetLastCommonNode(const vector<TreeNode*> &path_p,
                                const vector<TreeNode*> &path_q) {
        auto iter1 = path_p.begin();
        auto iter2 = path_q.begin();
        TreeNode* p_last = nullptr;
        while (iter1 != path_p.end() && iter2 != path_q.end()) {
            if (*iter1 == *iter2)
                p_last = *iter1;
            ++iter1, ++iter2;
        }
        return p_last;
    }
};

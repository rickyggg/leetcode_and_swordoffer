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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        stack<TreeNode*> stack1;  //存放奇数层节点
        stack<TreeNode*> stack2;  //存放偶数层节点
        stack1.push(root);
        while(!stack1.empty() || !stack2.empty()) {
            vector<int> tmp_res;
            if(!stack1.empty()) {
                while(!stack1.empty())      //清空stack1时，依次将栈顶节点子节点（先左后右）压入stack2
                {
                    TreeNode* tmp = stack1.top();
                    tmp_res.push_back(tmp->val);
                    stack1.pop();
                    if(tmp->left) stack2.push(tmp->left);      
                    if(tmp->right) stack2.push(tmp->right);
                }
            } else {
                while(!stack2.empty())       //清空stack2时，依次将栈顶节点子节点（先右后左）压入stack1
                {
                    TreeNode* tmp = stack2.top();
                    tmp_res.push_back(tmp->val);
                    stack2.pop();
                    if(tmp->right) stack1.push(tmp->right);
                    if(tmp->left) stack1.push(tmp->left);
                }
            }
            res.push_back(tmp_res);
        }
        return res;
    }
};

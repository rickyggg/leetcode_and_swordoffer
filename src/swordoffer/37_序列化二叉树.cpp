/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string res = "";
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *tmp = new TreeNode(0);
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                tmp = q.front();
                q.pop();
                if (tmp == nullptr)
                    res += '$';
                else
                    res.append(to_string(tmp->val));
                res += ',';
                if (tmp != nullptr) {
                    q.push(tmp->left);
                    q.push(tmp->right);
                }
            }
        }
        res.pop_back();
        delete tmp;
        return res;  
    }
    // Decodes your encoded s to tree.
    TreeNode* deserialize(string s) {
        if (s.empty()) return nullptr;
        int len = s.size();
        int i = 0;
        vector<TreeNode*> v;
        while (i < len) {
            string str = "";
            while (i < len && s[i] != ',') {
                str += s[i];
                ++i;
            }
            if (str == "$") {
                v.push_back(nullptr);
            } else {
                int temp = std::stoi(str);
                TreeNode * tmp = new TreeNode(temp);
                v.push_back(tmp);
            }
            ++i;
        }
        //遍历v，构建二叉树的结构。
        int j = 1;
        for (int i = 0; j < v.size(); i++) {
            if (v[i] == nullptr) continue;
            if (j < v.size()) v[i]->left = v[j++];
            if (j < v.size()) v[i]->right = v[j++];
        }
        return v[0];
    }
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        Node* head = nullptr, *pre = nullptr;
        helper(root, head, pre);
        head->left = pre;
        pre->right = head;                                                         
        return head;
    }
    void helper(Node* root, Node*& head, Node*& pre) {
        if (!root)  return;
        helper(root->left, head, pre);
        if(!head) {
            head = root;
            pre = root;
        } else {
            pre->right = root;
            root->left = pre;
            pre = root;
        }
        helper(root->right, head, pre);
    }
};
/* another answer
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        helper(root, v);
        for (int i = 0; i < v.size() - 1; ++i) {
            v[i]->right = v[i + 1];
            v[i + 1]->left = v[i];
        }
        v[0]->left = v[v.size() - 1];
        v[v.size() - 1]->right = v[0];
        return v[0];
    }
    void helper(Node* root, vector<Node*> v) {
        if (!root) return;
        helper(root->left, v);
        v.push_back(root);
        helper(root->right, v);
    }
private:
    vector<Node*> v;
};
*/

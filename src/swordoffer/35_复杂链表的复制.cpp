/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> m;
        Node *p = head;
        Node *copy_p = new Node(p->val);
        Node *new_head = copy_p;
        m[p] = copy_p;
        p = p->next;
        while (p) {
            copy_p->next = new Node(p->val);
            copy_p = copy_p->next;
            m[p] = copy_p;
            p = p->next;
        }
        p = head;
        copy_p = new_head;
        while (p) {
            copy_p->random = m[p->random];
            copy_p = copy_p->next;
            p = p->next;
        }
        return new_head;
    }
};

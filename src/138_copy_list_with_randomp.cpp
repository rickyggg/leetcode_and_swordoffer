class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (!head)
      return nullptr;
    unordered_map<Node *, Node *> m;
    Node *p = head;
    Node *copy_p = new Node(p->val);
    m[p] = copy_p;
    Node *new_head = copy_p;
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
      p = p->next;
      copy_p = copy_p->next;
    }
    return new_head;
  }
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = nullptr, *p = nullptr;
    head = new ListNode;
    p = head;
    int carry = 0;
    while (l1 || l2) {
      int v1 = l1 ? l1->val : 0;
      int v2 = l2 ? l2->val : 0;
      int tmp = v1 + v2 + carry;
      carry = tmp / 10;
      int val = tmp % 10;
      ListNode *new_node = new ListNode(val);
      p->next = new_node;
      p = new_node;
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }
    if (carry > 0) {
      ListNode *l = new ListNode(carry);
      p->next = l;
    }
    return head->next;
  }
};

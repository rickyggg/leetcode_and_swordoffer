class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head || !head->next || k == 0)
      return head;
    ListNode *p = head;
    int cnt = 1;
    while (p->next) {
      ++cnt;
      p = p->next;
    }
    p->next = head;
    k = k % cnt;
    while (--cnt >= k) {
      p = p->next;
    }
    head = p->next;
    p->next = nullptr;
    return head;
  }
};

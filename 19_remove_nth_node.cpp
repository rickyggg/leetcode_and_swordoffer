class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (!head)
      return nullptr;
    ListNode new_head(-1, head);
    ListNode *first = &new_head;
    ListNode *second = &new_head;
    for (int i = 0; i < n; i++)
      first = first->next;
    while (first->next) {
      first = first->next;
      second = second->next;
    }
    ListNode *p_deleted = second->next;
    second->next = second->next->next;
    delete p_deleted;
    return new_head.next;
  }
};

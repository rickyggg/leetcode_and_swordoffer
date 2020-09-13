class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (!head || !(head->next))
      return head;
    ListNode *first = nullptr, *second = head;
    while (second) {
      ListNode *tmp = second->next;
      second->next = first;
      first = second;
      second = tmp;
    }
    return first;
  }
};

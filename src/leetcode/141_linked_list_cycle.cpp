class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (!head)
      return false;
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (fast->val == slow->val)
        return true;
    }
    return false;
  }
};

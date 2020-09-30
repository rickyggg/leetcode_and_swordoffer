/*
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode;
    ListNode *p = head;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        p->next = new ListNode(l1->val);
        l1 = l1->next;
      } else {
        p->next = new ListNode(l2->val);
        l2 = l2->next;
      }
      p = p->next;
    }
    if (l1) {
      p->next = l1;
    }
    if (l2) {
      p->next = l2;
    }
    return head->next;
  }
};
*/
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) {
      return l2;
    } else if (l2 == nullptr) {
      return l1;
    }
    if (l1->val < l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    } else {
      l2->next = mergeTwoLists(l1, l2->next);
      return l2;
    }
  }
};

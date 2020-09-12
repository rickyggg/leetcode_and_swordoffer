class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    int n = Count(head, k);
    int cnt = n / k;
    ListNode *new_p, *old_p, *tmp_p, *tmp_head, *last_head;
    old_p = head;
    new_p = head->next;
    if (cnt == 1) {
      for (int i = 0; i < k - 1; ++i) {
        tmp_p = new_p->next;
        new_p->next = old_p;
        old_p = new_p;
        new_p = tmp_p;
      }
      head->next = new_p;
      head = old_p;
    } else {
      for (int i = 0; i < cnt; ++i) {
        last_head = head;
        if (i > 0) {
          head = last_head->next;
          old_p = head;
          new_p = head->next;
        }
        for (int j = 0; j < k - 1; ++j) {
          tmp_p = new_p->next;
          new_p->next = old_p;
          old_p = new_p;
          new_p = tmp_p;
        }
        head->next = new_p;
        if (i == 0) {
          tmp_head = old_p;
        } else {
          last_head->next = old_p;
        }
      }
      head = tmp_head;
    }
    return head;
  }
  int Count(ListNode *head, int k) {
    if (!head)
      return -1;
    ListNode *tmp = head;
    int cnt = 1;
    while (tmp->next) {
      ++cnt;
      tmp = tmp->next;
    }
    return cnt;
  }
};

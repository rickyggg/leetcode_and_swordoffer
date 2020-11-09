/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (!head)  return nullptr;
        ListNode *slow = head, *fast = head;
        while (k > 1) {
            fast = fast->next;
            --k;
            if (!fast)
                return nullptr;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

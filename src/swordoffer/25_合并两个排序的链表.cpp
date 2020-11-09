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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode;
        ListNode *p = head;
        while(l1 && l2) {
            if (l1->val < l2->val){
                ListNode *tmp = new ListNode(l1->val);
                l1 = l1->next;
                p->next = tmp;
                p = p->next;
            } else {
                ListNode *tmp = new ListNode(l2->val);
                l2 = l2->next;
                p->next = tmp;
                p = p->next;
            }
        }
        if (l1) 
            p->next = l1;
        if (l2)
            p->next = l2;
        return head->next;
    }
};

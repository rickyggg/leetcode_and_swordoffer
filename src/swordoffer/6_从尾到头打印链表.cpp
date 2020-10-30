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
    vector<int> reversePrint(ListNode* head) {
        if (!head) return {};
        stack<int> s;
        vector<int> res;
        while(head) {
            s.push(head->val);
            head = head->next;
        }
        res.reserve(s.size());
        while(!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode *t = head;
        while(t) {
            v.push_back(t->val);
            t = t->next;
        }
        sort(begin(v), end(v));
        t=head;
        for(auto i: v) {
            t->val = i;
            t=t->next;
        }
        return head;
    }
};
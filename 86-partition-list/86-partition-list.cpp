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
    ListNode* partition(ListNode* head, int x) {
        vector<int> v;
        ListNode *t = head;
        while(t) {
            v.emplace_back(t->val);
            t = t->next;
        }
        vector<int> ans;
        for(int i=0 ; i<v.size() ; ++i)
            if(v[i] < x)
                ans.emplace_back(v[i]);
        for(int i=0 ; i<v.size() ; ++i)
            if(v[i] >= x)
                ans.emplace_back(v[i]);
        t=head;
        int in = 0;
        while(t) {
            t->val = ans[in++];
            t = t->next;
        }
        return head;
    }
};
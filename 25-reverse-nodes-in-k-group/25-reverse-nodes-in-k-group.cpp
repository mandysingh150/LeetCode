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
    tuple<ListNode*,ListNode*,ListNode*> rev_k_nodes(ListNode *h, int k) {
        ListNode *prev=nullptr, *cur=h, *nxt;
        int cnt=k;
        while(cur and k>0) {
            prev=cur;
            cur=cur->next;
            k--;
        }
        if(k>0) {
            return {h, prev, cur};
        }
        prev=nullptr, cur=h, k=cnt;
        while(cur and k>0) {
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
            k--;
        }
        return {prev, h, cur};
    }
    ListNode* reverseKGroup(ListNode* node, int k) {
        ListNode *prev=nullptr, *cur=node, *ans;
        while(cur) {
            auto [head, tail, nxt] = rev_k_nodes(cur, k);
            if(prev) {
                prev->next=head;
            }
            else {
                ans = head;
            }
            prev = tail;
            prev->next = cur = nxt;
        }
        return ans;
    }
};
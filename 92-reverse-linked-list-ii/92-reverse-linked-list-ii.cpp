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
    pair<ListNode*,ListNode*> reverse(ListNode *n1, ListNode *n2) {
        ListNode *prev=nullptr, *cur=n1, *nxt;
        while(cur!=n2) {
            nxt = cur->next;
            cur->next = prev;
            prev=cur;
            cur=nxt;
        }
        cur->next = prev;
        return {n2, n1};
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
            return head;
        int diff = right-left;
        ListNode *cur = head, *prev=nullptr;
        while(--left) {
            prev = cur;
            cur=cur->next;
        }
        ListNode *left_node = cur;
        while(diff--) {
            cur = cur->next;
        }
        ListNode *next = cur->next;
        reverse(left_node, cur);
        if(prev) {
            prev->next = cur;
        }
        else {
            head = cur;
        }
        left_node->next = next;
        return head;
    }
};
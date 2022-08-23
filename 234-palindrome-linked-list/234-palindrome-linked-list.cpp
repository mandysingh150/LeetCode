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
    ListNode* rev(ListNode *h) {
        if(!h->next) return h;
        auto t = rev(h->next);
        h->next->next=h;
        return t;
    }
    bool isPalindrome(ListNode* root) {
        if(!root or !root->next) return 1;
        auto slow=root;
        auto fast=root->next;
        while(fast->next and fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        auto nxt = slow->next;
        slow->next=nullptr;
        nxt = rev(nxt);
        while(root and nxt) {
            if(root->val != nxt->val) return 0;
            root=root->next;
            nxt=nxt->next;
        }
        return 1;
    }
};
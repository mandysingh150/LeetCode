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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode *h=nullptr, *t=nullptr;
        int carry = 0;
        while(l1 and l2) {
            int val = l1->val + l2->val + carry;
            ListNode *tt = new ListNode(val%10);
            if(h==nullptr)
                h=t=tt;
            else
                t->next=tt, t=tt;
            carry = val/10;
            l1 = l1->next;
            l2=l2->next;
        }
        while(l1) {
            int val = l1->val + carry;
            ListNode *tt = new ListNode(val%10);
            if(h==nullptr)
                h=t=tt;
            else
                t->next=tt, t=tt;
            carry = val/10;
            l1 = l1->next;
        }
        while(l2) {
            int val = l2->val + carry;
            ListNode *tt = new ListNode(val%10);
            if(h==nullptr)
                h=t=tt;
            else
                t->next=tt, t=tt;
            carry = val/10;
            l2 = l2->next;
        }
        if(carry) {
            ListNode *tt = new ListNode(carry);
            t->next = tt;
            t = tt;            
        }
        return h;
    }
};
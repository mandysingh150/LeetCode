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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *h1=headA, *h2=headB;
        bool a=0, b=0;
        while(h1 and h2) {           
            if(h1 == h2)
                return h1;
            
            h1=h1->next;
            h2=h2->next;
            
            if(!h1 and !a)
                h1=headB, a=1;
            if(!h2 and !b)
                h2=headA, b=1;
        }
        return nullptr;
    }
};
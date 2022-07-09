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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return head;
        int cnt=0;
        ListNode *t = head, *ss=nullptr, *prev;
        while(t) {
            t=t->next;
            if(ss) {
                prev = ss;
                ss=ss->next;
            }
            if(++cnt == n) {
                prev=nullptr;
                ss=head;
            }
        }
        if(!prev) {
            return head->next;
        }
        else if(!ss->next) {
            prev->next=nullptr;
        }
        else {
            prev->next=ss->next;
        }
        return head;
    }
};
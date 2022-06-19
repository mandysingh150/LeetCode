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
    int countFromEnd = 0;
    ListNode* helper(ListNode* prev, ListNode* head, int n) {
        if(head==nullptr) {
            countFromEnd++;
            return nullptr;
        }
        head->next = helper(head, head->next, n);
        
        // remove this node
        if(countFromEnd==n) {
            if(prev==nullptr) {
                return head->next;
            }
            prev = head->next;
            head->next = nullptr;
            delete head;
            countFromEnd++;
            return prev;
        }
        
        countFromEnd++;
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) {
            return nullptr;
        }
        return helper(nullptr, head, n);
    }
};
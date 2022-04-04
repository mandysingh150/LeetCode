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
#define n nullptr

class Solution {
public:    
    int len;
    
    void func(ListNode *prev, ListNode *head, vector<ListNode*> &v, int num, int k) {
        if(head==n)
            return;
        
        len = max(num, len);
        if(num==k) {
            v.push_back(prev);
            v.push_back(head);   
        }
        
        func(head, head->next, v, num+1, k);
        
        if(len-num+1==k) {
            v.push_back(prev);
            v.push_back(head);   
        }
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        // Approach 1
        // When we reach k-th node, we set n1 to the current node, and n2 - to the head.
        // We continue traversing the list, but now we also move n2. When we reach the end, n2 will points to k-th node from end.
        ListNode *n1=n, *n2=n;
        for(ListNode *i=head ; i!=n ; i=i->next) {
            if(n2!=n)
                n2 = n2->next;
            --k;
            if(k==0) {
                n1 = i;
                n2 = head;
            }
        }
        swap(n1->val, n2->val);
        return head;
        
        // Approach 2
//         if(head->next==n)
//             return head;
//         else if(head->next->next==n) {
//             ListNode *next = head->next;
//             next->next = head;
//             head->next = n;
//             return next;
//         }
        
//         len = 1;
//         vector<ListNode*> v;
//         func(n, head, v, 1, k);
        
//         if(k>len/2) {
//             swap(v[0], v[2]);
//             swap(v[1], v[3]);
//             k = len-k+1;
//         }
        
//         if(k==1) {
//             head = v[3];
//             v[3]->next = v[1]->next;
//             v[2]->next = v[1];
//             v[1]->next = n;
//         }
//         else if(k == len-k) {
//             v[0]->next = v[3];
//             v[1]->next = v[3]->next;
//             v[3]->next = v[1];
//         }
//         else {
//             ListNode *n1 = v[1]->next;
//             ListNode *n2 = v[3]->next;
            
//             v[0]->next = v[3];
//             v[3]->next = n1;
//             v[2]->next = v[1];
//             v[1]->next = n2;            
//         }
//         return head;
    }
};
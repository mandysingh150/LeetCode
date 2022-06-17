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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkLL(ListNode* head, TreeNode* root) {
        head = head->next;
        while(head) {
            if(root->left and root->left->val == head->val and root->right and root->right->val == head->val)
                return checkLL(head, root->left) or checkLL(head, root->right);
            else if(root->left and root->left->val == head->val)
                root = root->left;
            else if(root->right and root->right->val == head->val)
                root = root->right;
            else
                return 0;
            head = head->next;
        }
        return head==NULL;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root) {
            if(root->val == head->val and checkLL(head, root))
                return 1;
            return isSubPath(head, root->left) or isSubPath(head, root->right);
        }
        return 0;
    }
};
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
    bool flipEquiv(TreeNode* r1, TreeNode* r2) {
        if(!r1 and !r2)
            return 1;
        if(r1 and r2)
            if(r1->val == r2->val)
                return (flipEquiv(r1->left, r2->left) and flipEquiv(r1->right, r2->right)) or (flipEquiv(r1->right, r2->left) and flipEquiv(r1->left, r2->right));
        return 0;
    }
};
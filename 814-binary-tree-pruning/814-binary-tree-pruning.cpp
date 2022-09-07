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
#define n nullptr
class Solution {
public:
    bool is1Found(TreeNode* root) {
        if(root==n)
            return 0;
        
        bool left=is1Found(root->left);
        bool right=is1Found(root->right);
        
        if(!left)
            root->left = n;
        if(!right)
            root->right = n;
        
        return left||right||(root->val==1);
    } 
    TreeNode* pruneTree(TreeNode* root) {
        is1Found(root);
        if(root->left==n and root->right==n and root->val==0)
            return n;
        return root;
    }
};
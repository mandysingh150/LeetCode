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
    int getLeftSubtreeHeight(TreeNode *root) {
        if(!root)
            return 0;
        
        int h=0;
        while(root)
            h++, root = root->left;
        return h;
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        int leftHeight = getLeftSubtreeHeight(root->left);
        int rightHeight = getLeftSubtreeHeight(root->right);
        
        if(leftHeight == rightHeight)
            return (1<<leftHeight) + countNodes(root->right);
        
        return (1<<rightHeight) + countNodes(root->left);
    }
};
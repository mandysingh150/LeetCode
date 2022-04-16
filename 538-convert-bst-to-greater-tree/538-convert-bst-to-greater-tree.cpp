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
    int sum;
    void h(TreeNode *root) {
        if(!root)
            return;
        h(root->right);
        sum += root->val;
        root->val = sum;
        h(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        sum=0;
        h(root);
        return root;
    }
};
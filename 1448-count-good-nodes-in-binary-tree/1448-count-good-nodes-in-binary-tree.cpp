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
    int ans;
    void help(TreeNode *root, int mx) {
        if(!root) return;
        if(root->val >= mx) ans++;
        help(root->left, max(root->val, mx));
        help(root->right, max(root->val, mx));
    }
    int goodNodes(TreeNode* root) {
        ans=0;
        help(root, INT_MIN);
        return ans;
    }
};
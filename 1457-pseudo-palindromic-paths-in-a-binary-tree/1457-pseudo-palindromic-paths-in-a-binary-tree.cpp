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
    int cnt=0;
    void h(TreeNode *root, int &val) {
        if(!root) return;
        val ^= (1<<(root->val));
        if(!root->left and !root->right) cnt += (val==0 or (val&(val-1)) == 0);
        else h(root->left, val), h(root->right, val);
        val ^= (1<<(root->val));
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        cnt=0;
        int val=0;
        h(root, val);
        return cnt;
    }
};
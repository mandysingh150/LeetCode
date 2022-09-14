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
    int pseudoPalindromicPaths(TreeNode* root, int val=0) {
        if(!root) return 0;
        val ^= (1<<(root->val));
        if(!root->left and !root->right) return (val==0 or (val&(val-1)) == 0);
        else return pseudoPalindromicPaths(root->left, val) + pseudoPalindromicPaths(root->right, val);
    }
};
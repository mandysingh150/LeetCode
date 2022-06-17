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
    int total=0;
    bool dfs(TreeNode *root, int val) {
        if(!root) 
            return 1;
        if(val > total) 
            return 0;
        if(val==0) {
            total++;
            return dfs(root->left, 0) and dfs(root->right, 0);
        }
        return dfs(root->left, val<<1) and dfs(root->right, (val<<1)+1);
    }
    bool isCompleteTree(TreeNode* root) {
        dfs(root, 0);
        
        if(!root) return 1;
        return dfs(root, 1);
    }
};
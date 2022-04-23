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
    int common_height(TreeNode *root) {
        int cnt=0;
        while(root) {
            root = root->left;
            cnt++;
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        int left_height = common_height(root->left);
        int right_height = common_height(root->right);
        
        if(left_height == right_height)
            return (1<<left_height) + countNodes(root->right);
        return (1<<right_height) + countNodes(root->left);
    }
};
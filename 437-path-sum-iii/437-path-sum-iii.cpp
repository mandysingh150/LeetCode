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
    void h(TreeNode *root, long long sum, int x, bool parent_used) {
        if(!root)
            return;
        if(!parent_used) {
            h(root->left, sum, x, 0);
            h(root->right, sum, x, 0);
        }
        sum += root->val;
        if(sum == x)
            ans++;
        h(root->left, sum, x, 1);
        h(root->right, sum, x, 1);
    }
    int pathSum(TreeNode* root, int targetSum) {
        ans=0;
        h(root, 0ll, targetSum, 0);
        return ans;
    }
};
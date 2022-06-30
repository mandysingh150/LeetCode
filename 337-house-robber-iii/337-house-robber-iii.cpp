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
    pair<int,int> h(TreeNode *root) {
        if(!root) {
            return {0,0};
        }
        auto [l_rob, l_skip] = h(root->left);
        auto [r_rob, r_skip] = h(root->right);
        return {root->val + l_skip + r_skip, max(l_rob, l_skip) + max(r_rob, r_skip)};
    }
    int rob(TreeNode* root) {
        auto [rob, skip] = h(root);
        return max(rob, skip);
    }
};
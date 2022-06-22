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
    // {balanced_or_not, height}
    pair<bool,int> h(TreeNode *root, int depth) {
        if(!root) {
            return {1, depth};
        }
        auto [left_bal, left_depth] = h(root->left, depth+1);
        auto [right_bal, right_depth] = h(root->right, depth+1);
        if(left_bal and right_bal and abs(left_depth-right_depth)<=1)
            return {1, max(left_depth, right_depth)};
        return {0, 0};
    }
    bool isBalanced(TreeNode* root) {
        return h(root, 0).first;
    }
};
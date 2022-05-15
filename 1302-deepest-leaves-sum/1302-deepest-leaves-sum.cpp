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
    unordered_map<int,int> mp;
    int mx_depth;
    void find_sum(TreeNode *root, int depth) {
        if(root) {
            mx_depth = max(mx_depth, depth);
            mp[depth] += root->val;
            find_sum(root->left, depth+1);
            find_sum(root->right, depth+1);
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        find_sum(root, 0);
        return mp[mx_depth];
    }
};
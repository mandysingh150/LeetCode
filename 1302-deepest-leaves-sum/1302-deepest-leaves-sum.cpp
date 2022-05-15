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
    int mx_depth, sum;
    void find_sum(TreeNode *root, int depth) {
        if(root) {
            if(mx_depth < depth) {
                mx_depth = depth;
                sum = 0;
            }
            if(depth == mx_depth)
                sum += root->val;
            find_sum(root->left, depth+1);
            find_sum(root->right, depth+1);
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        mx_depth = sum = 0;
        find_sum(root, 0);
        return sum;
    }
};
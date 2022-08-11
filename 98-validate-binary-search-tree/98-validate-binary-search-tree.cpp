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
#define tup tuple<bool, long long, long long>
class Solution {
public:
     tup h(TreeNode *root) {
        if(!root) return tup{1, LLONG_MAX, LLONG_MIN};
        auto [left_bst, left_mn, left_mx] = h(root->left);
        auto [right_bst, right_mn, right_mx] = h(root->right);
        if(left_bst and right_bst and left_mx<root->val and right_mn>root->val)
            return tup{1, min(left_mn, 0ll+root->val), max(right_mx, 0ll+root->val)};
        return tup{0, 0, 0};
    }
    bool isValidBST(TreeNode* root) {
        auto [a, _, _1] = h(root);
        return a;
    }
};
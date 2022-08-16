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
        if(!root) return {0,0};
        auto [lht, ld] = h(root->left);
        auto [rht, rd] = h(root->right);
        return pair<int,int>{1+max(lht, rht), max(1+lht+rht, max(ld, rd))};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root or (!root->left and !root->right)) return 0;
        return h(root).second-1;
    }
};
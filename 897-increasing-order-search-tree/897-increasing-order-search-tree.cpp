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
    TreeNode *node;
    void help(TreeNode *root) {
        if(root) {
            help(root->right);
            root->right = node;
            node = root;
            help(root->left);
            root->left=nullptr;
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        node=nullptr;
        help(root);
        return node;
    }
};
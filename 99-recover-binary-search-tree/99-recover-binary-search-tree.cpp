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
    TreeNode *prev, *ff, *ss;
    void inorder(TreeNode* root) {
        if(root) {
            inorder(root->left);
            
            // comparing current node (root) and prev, if prev exists
            if(prev and prev->val>root->val) {
                // if ff does not exist
                if(!ff) 
                    ff=prev;
                ss=root;
            }
            prev = root;
            
            inorder(root->right);
        }
    }
    void recoverTree(TreeNode* root) {
        ff = ss = prev = nullptr;
        inorder(root);
        swap(ff->val, ss->val);
    }
};
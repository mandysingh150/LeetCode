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
#define CAM_NEEDED 0
#define CAM_USED 1
#define CAM_NOT_NEEDED 2
class Solution {
public:
    int cnt=0;
    int h(TreeNode *root) {
        if(!root) {
            return CAM_NOT_NEEDED;
        }
        int left = h(root->left), right = h(root->right);
        if(left==CAM_NEEDED or right==CAM_NEEDED) {
            cnt++;
            return CAM_USED;
        }
        return left==CAM_USED or right==CAM_USED ? CAM_NOT_NEEDED : CAM_NEEDED;
    }
    int minCameraCover(TreeNode* root) {
        return (h(root) == CAM_NEEDED) + cnt;
    }
};
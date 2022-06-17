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
#define CAMERA_NOT_NEEDED 0
#define CAMERA_USED 1
#define CAMERA_NEEDED 2
class Solution {
public:
    int ans = 0;
    int dfs(TreeNode *root) {
        if(!root) {
            return CAMERA_NOT_NEEDED;
        }
        // CAMERA_NOT_NEEDED - leaf's parent's parent
        // CAMERA_USED - leaf's parent
        // CAMERA_NEEDED - leaf node
        int left = dfs(root->left), right = dfs(root->right);
        if(left==CAMERA_NEEDED or right==CAMERA_NEEDED) {
            ans++;
            return CAMERA_USED;
        }
        return (left==CAMERA_USED or right==CAMERA_USED) ? CAMERA_NOT_NEEDED : CAMERA_NEEDED;
    }
    int minCameraCover(TreeNode* root) {
        // we always want to add a camera at leaf's parent in order to minimize the # of cameras used
        return (dfs(root)==CAMERA_NEEDED) + ans;
    }
};
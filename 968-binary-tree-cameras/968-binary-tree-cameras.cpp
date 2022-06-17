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
    int ans;
    string dfs(TreeNode *root) {
        if(!root) {
            return "covered";
        }
        // "covered" - leaf's parent's parent
        // "covering" - leaf's parent
        // "to_be_covered" - leaf node
        string left = dfs(root->left), right = dfs(root->right);
        if(left=="to_be_covered" or right=="to_be_covered") {
            ans++;
            return "covering";
        }
        return (left=="covering" or right=="covering") ? "covered" : "to_be_covered";
    }
    int minCameraCover(TreeNode* root) {
        ans=0;
        // we always want to add a camera at leaf's parent in order to minimize the # of cameras used
        return (dfs(root)=="to_be_covered") + ans;
    }
};
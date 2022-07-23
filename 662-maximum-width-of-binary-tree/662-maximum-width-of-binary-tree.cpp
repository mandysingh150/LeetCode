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
    // for explanation, go here: "https://www.youtube.com/watch?v=ZbybYvcVLks"
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        // {node, node_number_on_current_level}
        queue<pair<TreeNode*,int>> q;
        // 0 based indexing
        q.push({root, 0});
        int mx=1;
        while(!q.empty()) {
            int mn = q.front().second;
            int sz=q.size();
            while(sz--) {
                auto [node, n] = q.front();
                q.pop();
                
                mx = max(mx, n-mn+1);
                if(node->left) {
                    q.push({node->left, 1ll*(n-mn)*2+1});
                }
                if(node->right) {
                    q.push({node->right, 1ll*(n-mn)*2+2});
                }
            }
        }
        return mx;
    }
};
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
    vector<vector<int>> levelOrder(TreeNode* r) {
        vector<vector<int>> v;
        if(r) {
            queue<TreeNode*> q;
            q.push(r);
            while(!q.empty()) {
                vector<int> t;
                int sz=q.size();
                while(sz--) {
                    auto root = q.front();
                    q.pop();
                    
                    t.push_back(root->val);
                    
                    if(root->left)
                        q.push(root->left);
                    if(root->right)
                        q.push(root->right);
                }
                v.push_back(t);
            }
        }
        return v;
    }
};
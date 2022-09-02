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
#define n nullptr
#define pb push_back
#define ff first
#define ss second

class Solution {
public:
    // peform a level order traversal and make the output array
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> v;
        
        if(root==n)
            return v;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(n);
        
        long long sum = 0;
        int depth=0,cnt=0;
        while(!q.empty()) {
            TreeNode *top = q.front();
            q.pop();
            
            if(top==n) {
                v.pb(1.0*sum/cnt);
                
                if(q.empty())
                    break;
                
                q.push(n);
                sum = 0;
                cnt = 0;
                
                top = q.front();
                q.pop();
            }

            sum += top->val;
            cnt++;
            if(top->left!=n) q.push(top->left);
            if(top->right!=n) q.push(top->right);
        }
        return v;
    }
};
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> v;
        
        // {node, x_coordinate}
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        int mn_x = 0;
        while(!q.empty()) {
            unordered_map<int,vector<int>> t;
            int sz = q.size();
            while(sz--) {
                auto [node, x] = q.front(); q.pop();
                mn_x = min(mn_x, x);
                t[x].push_back(node->val);
                if(node->left)
                    q.push({node->left, x-1});
                if(node->right)
                    q.push({node->right, x+1});
            }
            for(auto [x, values]: t) {
                sort(begin(values), end(values));
                for(auto val: values)
                    mp[x].push_back(val);
            }                
        }
        for(int i=mn_x ; mp.count(i) ; ++i)
            v.push_back(mp[i]);
        return v;
    }
};
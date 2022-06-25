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
    vector<TreeNode*> generateTrees(int end, int start=1) {
        if(start > end)
            return {nullptr};
        if(start==end)
            return {new TreeNode(start)};
        
        vector<TreeNode*> ans;
        for(int i=start ; i<=end ; ++i) {
            vector<TreeNode*> left = generateTrees(i-1, start);
            vector<TreeNode*> right = generateTrees(end, i+1);
            
            for(auto j: left) {
                for(auto k: right) {
                    ans.push_back(new TreeNode(i, j, k));
                }
            }
        }
        return ans;
    }
};
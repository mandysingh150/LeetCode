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
    TreeNode* h(vector<int>& pre, int pre_si, int pre_ei, vector<int>& post, int post_si, int post_ei) {
        if(pre_si > pre_ei)
            return nullptr;
        if(pre_si == pre_ei)
            return new TreeNode(pre[pre_si]);
        
        if(pre[pre_si+1] == post[post_ei-1])
            return new TreeNode(pre[pre_si], 
                h(pre, pre_si+1, pre_ei, post, post_si, post_ei-1), 
                nullptr
            );
        
        int pre_right_subtree_start_index = find(pre.begin()+pre_si, pre.begin()+pre_ei+1, post[post_ei-1]) - pre.begin();
        int post_left_subtree_end_index = find(post.begin()+post_si, post.begin()+post_ei+1, pre[pre_si+1]) - post.begin();
        return new TreeNode(pre[pre_si], 
            h(pre, pre_si+1, pre_right_subtree_start_index-1, post, post_si, post_left_subtree_end_index), 
            h(pre, pre_right_subtree_start_index, pre_ei, post, post_left_subtree_end_index+1, post_ei-1)
        );
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return h(preorder, 0, preorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
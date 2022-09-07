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
    string t;
    void help(TreeNode *root) {
        if(!root) return;
        t += to_string(root->val);

        if(!root->left and root->right) {
            t+="()";
            t.push_back('(');
            help(root->right);
            if(t[t.size()-1]=='(')
                t.pop_back();
            else
                t.push_back(')');
            
        }
        else {
            t.push_back('(');
            help(root->left);
            if(t[t.size()-1]=='(')
                t.pop_back();
            else
                t.push_back(')');

            t.push_back('(');
            help(root->right);
            if(t[t.size()-1]=='(')
                t.pop_back();
            else
                t.push_back(')');
        }   
    }
    string tree2str(TreeNode* root) {
        t="";
        help(root);
        return t;
    }
};
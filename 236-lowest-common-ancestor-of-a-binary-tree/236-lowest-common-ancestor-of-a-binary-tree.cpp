/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool h(TreeNode *r, TreeNode *a, vector<TreeNode*> &v) {
        if(!r) {
            return 0;
        }
        v.push_back(r);
        if(r == a or h(r->left, a, v) or h(r->right, a, v)) return 1;
        v.pop_back();
        return 0;        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> l, r;
        h(root, p, l);
        h(root, q, r);
        TreeNode *t;
        for(int i=0 ; i<l.size() and i<r.size() ; ++i) {
            if(l[i] != r[i]) break;
            t=l[i];
        }
        return t;
    }
};
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
    // int a[10], 
    int cnt=0;
    void h(TreeNode *root, int &val) {
        if(!root) return;
        // a[root->val]++;
        val ^= (1<<(root->val));
        if(!root->left and !root->right) {
            cnt += (val==0 or (val&(val-1)) == 0);
            // int odd_cnt=0;
            // for(int i=0 ; i<10 ; ++i) odd_cnt += (a[i]&1);
            // if(odd_cnt<=1) cnt++;
        }
        else {
            h(root->left, val);
            h(root->right, val);
        }
        // a[root->val]--;
        val ^= (1<<(root->val));
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        // memset(a, 0, sizeof(a));
        cnt=0;
        int val=0;
        h(root, val);
        return cnt;
    }
};
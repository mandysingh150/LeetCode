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
    vector<int> width;
    int mx;
    void h(TreeNode *root, int depth) {
        if(!root) {
            for(int i=depth ; i<width.size() ; ++i) {
                if((i-depth)<32 and width[i] + ((1ll)<<(i-depth)) < INT_MAX) {
                    width[i] += ((1ll)<<(i-depth));
                }
            }
            return;
        }
        if(depth == width.size()) {
            width.push_back(1);
        }
        else {
            width[depth]++;
        }
        mx = max(mx, width[depth]);
        h(root->left, depth+1);
        h(root->right, depth+1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        mx=0;
        h(root, 0);
        return mx;
    }
};
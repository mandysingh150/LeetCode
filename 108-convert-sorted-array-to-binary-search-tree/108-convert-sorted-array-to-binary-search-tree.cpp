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
    TreeNode* h(vector<int> &a, int si, int ei) {
        if(si>=ei) {
            if(si == ei)
                return new TreeNode(a[si]);
            return nullptr;
        }
        int mid = (si+ei)>>1;
        return new TreeNode (a[mid], h(a, si, mid-1), h(a, mid+1, ei));
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return h(nums, 0, nums.size()-1);
    }
};
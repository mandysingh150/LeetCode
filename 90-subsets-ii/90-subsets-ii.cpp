class Solution {
public:
    void h(vector<int> &a, int in, vector<int> &v, set<vector<int>> &s) {
        if(a.size()==in) {
            s.insert(v);
            return;
        }
        h(a, in+1, v, s);
        v.push_back(a[in]);
        h(a, in+1, v, s);
        v.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<int> v;
        h(nums, 0, v, s);
        return vector<vector<int>>(s.begin(), s.end());
    }
};
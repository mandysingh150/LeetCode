class Solution {
public:
    vector<vector<int>> ans;
    void h(vector<int> &a, int in, int x, vector<int> &t) {
        if(in == a.size()) {
            if(x == 0) {
                ans.push_back(t);
            }
            return;
        }
        if(a[in] <= x) {
            t.push_back(a[in]);
            h(a, in, x-a[in], t);
            t.pop_back();
        }
        h(a, in+1, x, t);
    }
    vector<vector<int>> combinationSum(vector<int>& a, int x) {
        vector<int> t;
        h(a, 0, x, t);
        return ans;
    }
};
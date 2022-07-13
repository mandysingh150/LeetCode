class Solution {
public:
    vector<vector<int>> ans;
    void h(vector<int> &a, int in, int x, vector<int> &t) {
        if(x <= 0) {
            if(x == 0) {
                ans.push_back(t);
            }
            return;
        }
        if(in == a.size()) {
            return;
        }
        int i=0;
        while(i*a[in]<=x) {
            h(a, in+1, x-a[in]*i, t);
            t.push_back(a[in]);
            i++;
        }
        while(i--) {
            t.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& a, int x) {
        vector<int> t;
        h(a, 0, x, t);
        return ans;
    }
};
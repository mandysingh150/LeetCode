class Solution {
public:
    vector<vector<int>> s;
    void h(vector<int> &a, int x, int in, vector<int> &v) {
        if(in == a.size() or x == 0) {
            if(x == 0) {
                s.push_back(v);
            }
            return;
        }
        for(int i=0 ; i*a[in]<=x ; ++i) {
            if(i>0) {
                v.push_back(a[in]);
            }
            h(a, x-(i*a[in]), in+1, v);
        }
        while(!v.empty() and v.back() == a[in])
            v.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& a, int x) {
        s.clear();
        vector<int> v;
        h(a, x, 0, v);
        return s;
    }
};
class Solution {
public:
    vector<vector<int>> v;
    void h(vector<int> &a, int in, int x, vector<int> &t) {
        if(x == 0) {
            v.push_back(t);
            return;
        }
        if(in == a.size()) {
            return;
        }
        for(int i=in ; i<a.size() and a[i]<=x ; ++i) {
            if(i==in or a[i]!=a[i-1]) {
                t.push_back(a[i]);
                h(a, i+1, x-a[i], t);
                t.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int x) {
        sort(begin(a), end(a));
        vector<int> t;
        h(a, 0, x, t);
        return v;
    }
};
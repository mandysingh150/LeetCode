class Solution {
public:
    int mn, a[12];
    void h(vector<int> &v, int in, int k, int mx) {
        if(mx >= mn)
            return;
        if(in == v.size()) {
            mn = min(mn, mx);
            return;
        }
        unordered_set<int> s;
        for(int i=0 ; i<k ; ++i) {
            if(s.count(a[i])) {
                continue;
            }
            if(a[i]+v[in] >= mn) {
                continue;
            }
            
            s.insert(a[i]);
            a[i] += v[in];
            h(v, in+1, k, max(mx, a[i]));
            a[i] -= v[in];
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        if(k == jobs.size()) {
            return *max_element(begin(jobs), end(jobs));
        }
        sort(begin(jobs), end(jobs), greater<int>());
        mn=0;
        for(auto &i: jobs) mn += i;
        memset(a, 0, sizeof(a));
        h(jobs, 0, k, 0);
        return mn;
    }
};
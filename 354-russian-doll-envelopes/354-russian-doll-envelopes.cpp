class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& a) {
        sort(begin(a), end(a), [](vector<int> &c, vector<int> &d) {
            if(c[0] == d[0])
                return c[1] > d[1];
            return c[0]<d[0];
        });
        vector<int> v = {a[0][1]};
        for(int i=0 ; i<a.size() ; ++i) {
            auto in = lower_bound(begin(v), end(v), a[i][1]) - begin(v);
            if(in == v.size()) 
                v.push_back(a[i][1]);
            else 
                v[in] = a[i][1];
        }
        return v.size();
    }
};
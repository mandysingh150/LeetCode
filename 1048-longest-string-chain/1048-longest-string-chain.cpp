class Solution {
public:
    int longestStrChain(vector<string>& a) {
        sort(begin(a), end(a), [](string &c, string &d) {
            return c.size() < d.size();        
        });
        unordered_map<string,int> mp;
        for(int i=0 ; i<a.size() ; ++i) {
            mp[a[i]] = i;
        }
        vector<int> v(a.size(), 1);
        int mx=1;
        for(int i=0 ; i<a.size() ; ++i) {
            for(int j=0 ; j<a[i].size() ; ++j) {
                string t = a[i].substr(0,j) + a[i].substr(j+1);
                if(mp.count(t)) {
                    v[i] = max(v[i], 1+v[mp[t]]);
                    mx = max(v[i], mx);
                }
            }
        }
        return mx;
    }
};
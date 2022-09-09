class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& a) {
        sort(begin(a), end(a));
        unordered_map<int,int> mp;
        int mx=0, cnt=0;
        for(int i=a.size()-1 ; i>=0 ; --i) mx = mp[a[i][0]] = max(mp[a[i][0]], max(mx, a[i][1]));
        for(auto i: a) {
            auto in = lower_bound(begin(a), end(a), vector<int>{i[0]+1, i[1]+1}) - begin(a);
            cnt += (in < a.size() and mp[a[in][0]] > i[1]);
        }
        return cnt;
    }
};
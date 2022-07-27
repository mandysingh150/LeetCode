int dp[50005];
class Solution {
public:
    int h(vector<vector<int>> &v, int in) {
        if(in == v.size()) {
            return 0;
        }
        if(dp[in] != -1) {
            return dp[in];
        }
        return dp[in] = max(v[in][2] + h(v, lower_bound(begin(v), end(v), vector<int>{v[in][1], 0, 0}) - v.begin()), h(v, in+1));
    }
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& pr) {
        vector<vector<int>> v(st.size());
        for(int i=0 ; i<st.size() ; ++i) {
            v[i] = {st[i], et[i], pr[i]};
        }
        sort(begin(v), end(v));
        memset(dp, -1, sizeof(dp));
        return h(v, 0);
    }
};
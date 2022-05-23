int dp[601][101][101], ans;
class Solution {
public:
    int h(vector<pair<int,int>>& a, int m, int n, int i) {
        if(i==a.size())
            return 0;
        if(dp[i][m][n] != -1)
            return dp[i][m][n];
        int a1 = h(a, m, n, i+1), a2=0;
        if(a[i].first<=m and a[i].second<=n)
            a2 = 1 + h(a, m-a[i].first, n-a[i].second, i+1);
        dp[i][m][n] = max(a1, a2);
        ans = max(ans, dp[i][m][n]);
        return dp[i][m][n];
    }
    
    int findMaxForm(vector<string>& s, int m, int n) {
        ans = 0;
        memset(dp, -1, sizeof(dp));
        vector<pair<int,int>> v;
        for(auto i: s) {
            int cnt0=0, cnt1=0;
            for(auto j: i)
                j=='1' ? cnt1++ : cnt0++;
            v.push_back({cnt0, cnt1});
        }
        h(v, m, n, 0);
        return ans;
    }
};
long long dp[201][201], mp[201][201];
class Solution {
public:
    long long h(int m, int n) {
        if(m==1 and n==1)
            return mp[m][n];
        if(dp[m][n] != -1)
            return dp[m][n];
        
        long long ans=mp[m][n];
        for(int i=1 ; i<=m>>1 ; ++i) {
            ans = max(ans, h(i, n) + h(m-i, n));
        }
        for(int i=1 ; i<=n>>1 ; ++i) {
            ans = max(ans, h(m, i) + h(m, n-i));
        }
        return dp[m][n] = ans;
    }
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        memset(mp, 0, sizeof(mp));
        memset(dp, -1, sizeof(dp));
        for(auto i: prices) {
            mp[i[0]][i[1]] = i[2];
        }
        return h(m, n);
    }
};
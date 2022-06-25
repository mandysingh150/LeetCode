class Solution {
public:
    long long dp[201][201], price[201][201];
    long long h(int m, int n) {
        if(dp[m][n] != -1)
            return dp[m][n];
        long long ans=price[m][n];
        for(int i=1 ; i<=m/2 ; ++i) {
            ans = max(ans, h(i, n) + h(m-i, n));
        }
        for(int i=1 ; i<=n/2 ; ++i) {
            ans = max(ans, h(m, i) + h(m, n-i));
        }
        return dp[m][n] = ans;
    }
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        memset(price, 0, sizeof(price));
        memset(dp, -1, sizeof(dp));
        for(auto i: prices) {
            price[i[0]][i[1]] = i[2];
        }
        return h(m, n);        
    }
};
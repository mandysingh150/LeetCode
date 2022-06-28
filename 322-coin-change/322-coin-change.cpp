class Solution {
public:
    int coinChange(vector<int>& a, int x) {
        int n=a.size();
        sort(begin(a), end(a));
        vector<vector<int>> dp(n+1, vector<int>(x+1));
        for(int i=0 ; i<=n ; ++i) {
            for(int j=0 ; j<=x ; ++j) {
                if(i==0 and j==0) {
                    dp[i][j] = 0;
                }
                else if(i==0) {
                    dp[i][j]=INT_MAX-1;
                }
                else if(j==0) {
                    dp[i][j]=0;
                }
                else {
                    if(j >= a[i-1]) {
                        dp[i][j] = min(dp[i-1][j], 1+dp[i][j-a[i-1]]);
                    }
                    else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        return dp[n][x]==INT_MAX-1 ? -1 : dp[n][x];
    }
};
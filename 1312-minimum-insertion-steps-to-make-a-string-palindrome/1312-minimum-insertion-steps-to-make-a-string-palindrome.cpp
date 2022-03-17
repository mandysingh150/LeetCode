class Solution {
public:
    int lcs(string &s, string &t) {
        int n = s.size();
        int dp[n+1][n+1];
        for(int i=0 ; i<=n ; ++i)
            for(int j=0 ; j<=n ; ++j)
                dp[i][j] = (i==0 or j==0 ? 0 : (s[i-1]==t[j-1] ? 1+dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1])));
        return dp[n][n];
    }
    int minInsertions(string s) {
        string t = s;
        reverse(begin(t), end(t));
        return s.size()-lcs(s,t);
    }
};
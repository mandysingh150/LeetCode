int dp[200][200];
class Solution {
public:
    int h(vector<vector<int>>& a, int r, int c) {
        if(r == a.size())
            return 0;
        if(dp[r][c] != -1)
            return dp[r][c];
        
        return dp[r][c] = a[r][c] + min(h(a, r+1, c), h(a, r+1, c+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp, -1, sizeof(dp));
        return h(triangle, 0, 0);
    }
};
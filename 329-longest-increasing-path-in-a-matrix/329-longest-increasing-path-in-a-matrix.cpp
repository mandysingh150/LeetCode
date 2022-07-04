int dir[]={-1,0,1,0,-1};
class Solution {
public:
    int dp[201][201], m, n, mx;
    int h(vector<vector<int>>& a, int i, int j) {
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans=0;
        for(int k=0 ; k<4 ; ++k) {
            int r=i+dir[k], c=j+dir[k+1];
            if(r>=0 and r<m and c>=0 and c<n and a[r][c]>a[i][j]) {
                ans = max(ans, h(a, r, c));
            }
        }
        return dp[i][j] = 1+ans;
    }
    int longestIncreasingPath(vector<vector<int>>& a) {
        memset(dp, -1, sizeof(dp));
        m=a.size(), n=a[0].size(), mx=0;
        for(int i=0 ; i<m ; ++i) {
            for(int j=0 ; j<n ; ++j) {
                mx = max(mx, h(a, i, j));
            }
        }
        return mx;
    }
};
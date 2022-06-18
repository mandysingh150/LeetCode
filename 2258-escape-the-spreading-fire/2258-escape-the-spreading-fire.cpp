#define tup tuple<int,int,int>
class Solution {
public:
    int maximumMinutes(vector<vector<int>>& a) {
        int m=a.size(), n=a[0].size();
        auto bfs = [&](bool is_fire) {
            vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
            queue<tup> q;
            int dir[]={-1,0,1,0,-1};
            if(is_fire) {
                for(int i=0 ; i<m ; ++i) {
                    for(int j=0 ; j<n ; ++j) {
                        if(a[i][j] == 1) {
                            q.push(tup{0, i ,j});
                            dp[i][j] = 0;
                        }
                    }
                }
            }
            else {
                q.push(tup{0, 0, 0});
                dp[0][0] = 0;
            }
            while(!q.empty()) {
                auto [val, r, c] = q.front();
                q.pop();
                
                for(int i=0 ; i<4 ; ++i) {
                    int x=r+dir[i], y=c+dir[i+1];
                    if(x>=0 and x<m and y>=0 and y<n and a[x][y]==0 and 1+val<dp[x][y]) {
                        dp[x][y] = 1 + val;
                        q.push(tup{dp[x][y], x, y});
                    }
                }
            }
            return vector<int>{dp[m-1][n-1], dp[m-1][n-2], dp[m-2][n-1]};
        };
        auto f=bfs(1), p=bfs(0);
        if(f[0]==INT_MAX and p[0]!=INT_MAX)
            return 1e9;
        int diff=f[0]-p[0];
        if(p[0]!=INT_MAX and diff>=0)
            return diff - (f[1]-p[1]<=diff and f[2]-p[2]<=diff);
        return -1;
    }
};
int dir[] = {-1,0,1,0,-1};
class Solution {
public:
    int regionsBySlashes(vector<string>& a) {
        int n=a.size();
        int dp[n*3][n*3];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0 ; i<n ; ++i) {
            for(int j=0 ; j<n ; ++j) {
                if(a[i][j] == '/')
                    dp[i*3][j*3+2] = dp[i*3+1][j*3+1] = dp[i*3+2][j*3] = 1;
                else if(a[i][j] == '\\')
                    dp[i*3][j*3] = dp[i*3+1][j*3+1] = dp[i*3+2][j*3+2] = 1;
            }
        }
        int cnt=0;
        for(int i=0 ; i<3*n ; ++i) {
            for(int j=0 ; j<3*n ; ++j) {
                if(dp[i][j]==0) {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    dp[i][j] = 1;
                    cnt++;
                    while(!q.empty()) {
                        auto [row, col] = q.front();
                        q.pop();

                        for(int k=0 ; k<4 ; ++k) {
                            int x = row+dir[k], y = col+dir[k+1];
                            if(x>=0 and x<3*n and y>=0 and y<3*n and dp[x][y]==0)
                                q.push({x, y}), dp[x][y]=1;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
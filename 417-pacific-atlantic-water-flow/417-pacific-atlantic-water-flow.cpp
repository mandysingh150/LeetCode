int dir[]={-1,0,1,0,-1};
class Solution {
public:
    int dp[201][201];
    void BFS(vector<vector<int>> &a, bool pacific) {
        queue<pair<int,int>> q;
        int row = (pacific ? 0 : a.size()-1);
        int col = (pacific ? 0 : a[0].size()-1);
        vector<vector<int>> vis(a.size(), vector<int>(a[0].size(), 0));
        for(int i=0 ; i<a.size() ; ++i) {
            for(int j=0 ; j<a[0].size() ; ++j) {
                if(i==row or j==col) {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            dp[r][c]++;
            for(int i=0 ; i<4 ; ++i) {
                int x=r+dir[i], y=c+dir[i+1];
                if(x>=0 and x<a.size() and y>=0 and y<a[0].size() and !vis[x][y] and a[x][y]>=a[r][c]) {
                    vis[x][y]=1;
                    q.push({x,y});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
        memset(dp, 0, sizeof(dp));
        BFS(a, 1);
        BFS(a, 0);
        vector<vector<int>> ans;
        for(int i=0 ; i<a.size() ; ++i) {
            for(int j=0 ; j<a[0].size() ; ++j) {
                if(dp[i][j] == 2) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
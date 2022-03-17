int dir[] = {-1,0,1,0,-1};
class Solution {
public:
    int m,n;
    void bfs(vector<vector<int>> &h, queue<pair<int,int>> &q, vector<vector<int>> &vis, vector<vector<int>> &ans) {
        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for(int k=0 ; k<4 ; ++k) {
                int x=row+dir[k], y=col+dir[k+1];
                if(x>=0 and x<m and y>=0 and y<n and h[row][col]<=h[x][y] and !vis[x][y]) {
                    q.push({x,y});
                    ans[x][y]++;
                    vis[x][y]=1;
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        m=h.size(), n=h[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0)), ans(m, vector<int>(n, 0)), v;
        queue<pair<int,int>> q;
        for(int i=0 ; i<m ; ++i)
            for(int j=0 ; j<n ; ++j)
                if(i==0 or j==0)
                    q.push({i,j}), vis[i][j]=1, ans[i][j]++;
        bfs(h, q, vis, ans);
        for(int i=0 ; i<m ; ++i)
            for(int j=0 ; j<n ; ++j) {
                vis[i][j] = 0;
                if(i==m-1 or j==n-1)
                    q.push({i,j}), vis[i][j]=1, ans[i][j]++;
            }
        bfs(h, q, vis, ans);
        for(int i=0 ; i<m ; ++i)
            for(int j=0 ; j<n ; ++j)
                if(ans[i][j]==2)
                    v.push_back({i,j});
        return v;
    }
};
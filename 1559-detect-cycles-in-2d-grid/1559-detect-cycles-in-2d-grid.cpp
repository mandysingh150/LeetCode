int dir[] = {-1,0,1,0,-1};
class Solution {
public:
    int m,n;
    bool loop_found(vector<vector<char>> &a, int prev_r, int prev_c, int r, int c, vector<vector<int>> &vis) {
        if(vis[r][c])
            return 1;
        vis[r][c]=1;
        bool ans=0;
        for(int i=0 ; i<4 ; ++i) {
            int x=r+dir[i], y=c+dir[i+1];
            if(x>=0 and x<m and y>=0 and y<n and (x!=prev_r or y!=prev_c) and a[x][y]==a[r][c] and loop_found(a, r, c, x, y, vis))
                return 1;
        }
        return 0;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m=grid.size(), n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        bool ans=0;
        for(int i=0 ; i<m ; ++i) {
            for(int j=0 ; j<n ; ++j) {
                if(!vis[i][j]) {
                    // ans |= loop_found(grid, -1, -1, i, j, vis);
                    vis[i][j]=1;
                    for(int k=0 ; k<4 ; ++k) {
                        int x=i+dir[k], y=j+dir[k+1];
                        if(x>=0 and x<m and y>=0 and y<n and grid[x][y]==grid[i][j] and loop_found(grid, i, j, x, y, vis))
                            return 1;
                    }
                }
            }
        }
        return 0;
    }
};
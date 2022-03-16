class Solution {
public:
    int dirs[6][2][2] = {
        {{0, -1}, {0, 1}},
        {{-1, 0}, {1, 0}},
        {{0, -1}, {1, 0}},
        {{0, 1}, {1, 0}},
        {{0, -1}, {-1, 0}},
        {{0, 1}, {-1, 0}}
    };
    //the idea is you need to check port direction match, you can go to next cell and check whether you can come back.
    bool hasValidPath(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        q.push({0, 0});
        visited[0][0] = 1;
        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            int num = grid[x][y] - 1;
            for(int i=0 ; i<2 ; ++i) {
                int nx = x + dirs[num][i][0], ny = y + dirs[num][i][1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) 
                    continue;
                //go to the next cell and come back to orign to see if port directions are same
                for(int i=0 ; i<2 ; ++i) {
                    if (nx+dirs[grid[nx][ny]-1][i][0]==x && ny+dirs[grid[nx][ny]-1][i][1]==y) {
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return visited[m - 1][n - 1];
    }
};
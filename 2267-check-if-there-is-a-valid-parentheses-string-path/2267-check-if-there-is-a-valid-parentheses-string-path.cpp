#define tup tuple<int,int,int>
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& a) {
        if(a[0][0] == ')')
            return 0;
        
        // {left_cnt-right_cnt, row, col}
        queue<tup> q;
        int m=a.size(), n=a[0].size();
        int dir[2][2] = {{1,0}, {0,1}};
        int vis[1001][100][100];
        memset(vis, 0, sizeof(vis));
        
        q.push({1,0,0});
        vis[1][0][0] = 1;
        while(!q.empty()) {
            auto [diff, row, col] = q.front();
            q.pop();
            
            if(row==m-1 and col==n-1 and diff==0)
                return 1;
            
            for(int i=0 ; i<2 ; ++i) {
                int r=row+dir[i][0], c=col+dir[i][1];
                if(r<m and c<n) {
                    int new_diff = diff + (a[r][c]=='(' ? 1 : -1);
                    if(new_diff>=0 and new_diff<=(m+n)/2 and vis[new_diff][r][c] == 0) {
                        q.push({new_diff, r, c});
                        vis[new_diff][r][c] = 1;
                    }
                }
            }
        }
        return 0;
    }
};
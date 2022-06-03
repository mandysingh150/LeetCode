class Solution {
public:
    bool hasValidPath(vector<vector<char>>& a) {
        if(a[0][0] == ')')
            return 0;
        
        int m=a.size(), n=a[0].size();
        vector<pair<int,int>> d = {{0,1}, {1,0}};
        queue<tuple<int,int,int>> q;
        int vis[1001][100][100];
        memset(vis, 0, sizeof(vis));
        
        q.push({1, 0, 0});
        vis[1][0][0] = 1;
        while(!q.empty()) {
            auto [diff, r, c] = q.front();
            q.pop();
            
            if(r==m-1 and c==n-1 and diff==0)
                return 1;
            
            for(int i=0 ; i<2 ; ++i) {
                int row=r+d[i].first, col=c+d[i].second;
                if(row<m and col<n) {
                    int new_diff = diff + (a[row][col]=='(' ? 1 : -1);
                    if(new_diff>=0 and new_diff<=(m+n)/2 and vis[new_diff][row][col]==0) {
                        q.push({new_diff, row, col});
                        vis[new_diff][row][col] = 1;
                    }
                }
            }
        }
        return 0;
    }
};
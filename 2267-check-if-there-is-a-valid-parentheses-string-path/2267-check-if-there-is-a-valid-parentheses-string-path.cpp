#define tup tuple<int,int,int>
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& a) {
        if(a[0][0] == ')') {
            return 0;
        }
        int m=a.size(), n=a[0].size();
        queue<tup> q;
        int vis[1001][100][100];
        int dir[2][2] = {{1,0}, {0,1}};
        memset(vis, 0, sizeof(vis));
        
        q.push({1,0,0});
        vis[1][0][0] = 1;
        while(!q.empty()) {
            // auto [val, r, c] = q.top();
            auto [val, r, c] = q.front();
            q.pop();
            
            if(r==m-1 and c==n-1 and val==0)
                return 1;
            
            for(int i=0 ; i<2 ; ++i) {
                int x=dir[i][0]+r, y=dir[i][1]+c;
                if(x>=0 and y>=0 and x<m and y<n) {
                    int new_val = val + (a[x][y]=='(' ? 1 : -1);
                    if(new_val>=0 and new_val<=(m+n)/2 and !vis[new_val][x][y]) {
                        vis[new_val][x][y] = 1;
                        q.push(tup{new_val, x, y});
                    }
                }
            }
        }
        return 0;
    }
};
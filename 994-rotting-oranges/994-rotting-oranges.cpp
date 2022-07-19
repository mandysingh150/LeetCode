int dir[]={-1,0,1,0,-1};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0 ; i<a.size() ; ++i) {
            for(int j=0 ; j<a[0].size() ; ++j) {
                if(a[i][j] == 1) fresh++;
                else if(a[i][j] == 2) q.push({i,j});
            }
        }
        if(fresh==0) {
            return 0;
        }
        int ans=-1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [row, col] = q.front();
                q.pop();
                
                for(int i=0 ; i<4 ; ++i) {
                    int r=row+dir[i], c=col+dir[i+1];
                    if(r>=0 and c>=0 and c<a[0].size() and r<a.size() and a[r][c]==1) {
                        a[r][c]=2;
                        q.push({r,c});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        return fresh==0 ? ans : -1;
    }
};
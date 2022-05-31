int dir[]={-1,0,1,0,-1};
#define piii pair<int,pair<int,int>>
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& a) {
        int m=a.size(), n=a[0].size();
        priority_queue<piii, vector<piii>, greater<piii>> pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX-1));
        dist[0][0] = a[0][0];
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int val=top.first, r=top.second.first, c=top.second.second;
            if(r==m-1 and c==n-1)
                break;
            
            for(int i=0 ; i<4 ; ++i) {
                int row=r+dir[i] ,col=c+dir[i+1];
                if(row>=0 and row<m and col>=0 and col<n and val + a[row][col] < dist[row][col]) {
                    dist[row][col] = val + a[row][col];
                    pq.push({dist[row][col], {row, col}});
                }
            }
        }
        return dist[m-1][n-1];
    }
};
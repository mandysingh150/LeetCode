int dir[]={-1,0,1,0,-1};
#define tup tuple<int,int,int>
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& a) {
        // Dijkstra's algorithm
        int m=a.size(), n=a[0].size();
        // {obstacles, row, col}
        priority_queue<tup, vector<tup>, greater<tup>> pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX-1));
        dist[0][0] = a[0][0];
        pq.push({0,0,0});
        while(!pq.empty()) {
            auto [val, r, c] = pq.top();
            pq.pop();
            
            if(r==m-1 and c==n-1)
                return val;
            
            for(int i=0 ; i<4 ; ++i) {
                int row=r+dir[i], col=c+dir[i+1];
                if(row>=0 and row<m and col>=0 and col<n and a[row][col]+val<dist[row][col]) {
                    dist[row][col] = a[row][col]+dist[r][c];
                    pq.push(tup{dist[row][col], row, col});
                }
            }
        }
        return -1;
    }
};
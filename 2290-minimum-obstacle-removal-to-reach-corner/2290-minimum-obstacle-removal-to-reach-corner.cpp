#define tup tuple<int,int,int>
int dir[]={-1,0,1,0,-1};
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& a) {
        priority_queue<tup, vector<tup>, greater<tup>> pq;
        int m=a.size(), n=a[0].size();
        vector<vector<int>> d(m, vector<int>(n, INT_MAX-1));
        pq.push({0, 0, 0});
        while(!pq.empty()) {
            auto [dis, row, col] = pq.top();
            pq.pop();
            
            if(row == m-1 and col == n-1) {
                return dis;
            }
            
            for(int i=0 ; i<4 ; ++i) {
                int r=dir[i]+row, c=dir[i+1]+col;
                if(r>=0 and c>=0 and r<m and c<n and dis+a[r][c]<d[r][c]) {
                    d[r][c] = a[r][c] + dis;
                    pq.push(tup{d[r][c], r, c});
                }
            }
        }
        return -1;
    }
};
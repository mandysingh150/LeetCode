class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int dir=0, cnt=1;
        pair<int,int> row={0,n-1}, col={0,n-1};
        vector<vector<int>> v(n, vector<int>(n));
        while(cnt<=n*n) {
            for(int i=col.first ; cnt<=n*n and i<=col.second ; ++i)
                v[row.first][i] = cnt++;
            row.first++;
            for(int i=row.first ; cnt<=n*n and i<=row.second ; ++i)
                v[i][col.second] = cnt++;
            col.second--;
            for(int i=col.second ; cnt<=n*n and i>=col.first ; --i)
                v[row.second][i] = cnt++;
            row.second--;
            for(int i=row.second ; cnt<=n*n and i>=row.first ; --i)
                v[i][col.first] = cnt++;
            col.first++;
        }
        return v;
    }
};
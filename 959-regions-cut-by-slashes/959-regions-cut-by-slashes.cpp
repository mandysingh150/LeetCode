int dir[]={-1,0,1,0,-1};
class Solution {
public:
    int cnt, m, n;
    void dfs(vector<vector<int>> &v, int i, int j) {
        v[i][j]=1;
        for(int k=0 ; k<4 ; ++k) {
            int x=i+dir[k], y=j+dir[k+1];
            if(x>=0 and x<v.size() and y>=0 and y<v[0].size() and v[x][y]==0)
                dfs(v, x, y);
        }
    }
    int regionsBySlashes(vector<string>& a) {
        m=a.size(), n=a[0].size(), cnt=0;
        vector<vector<int>> v(m*3, vector<int>(n*3, 0));
        for(int i=0 ; i<m ; ++i) {
            for(int j=0 ; j<n ; ++j) {
                if(a[i][j] == '/') {
                    v[i*3][j*3+2] = v[i*3+1][j*3+1] = v[i*3+2][j*3] = 1;
                }
                else if(a[i][j] == '\\') {
                    v[i*3][j*3] = v[i*3+1][j*3+1] = v[i*3+2][j*3+2] = 1;
                }
            }
        }
        for(int i=0 ; i<m*3 ; ++i) {
            for(int j=0 ; j<n*3 ; ++j) {
                if(v[i][j] == 0) {
                    cnt++;
                    dfs(v, i, j);
                }                    
            }
        }
        return cnt;
    }
};
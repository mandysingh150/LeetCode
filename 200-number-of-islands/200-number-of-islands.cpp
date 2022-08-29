int dir[]={-1,0,1,0,-1};
class Solution {
public:
    void dfs(vector<vector<char>>& a, int r, int c) {
        a[r][c]='0';
        for(int i=0 ; i<4 ; ++i) {
            int rr=r+dir[i], cc=c+dir[i+1];
            if(rr>=0 and rr<a.size() and cc>=0 and cc<a[0].size() and a[rr][cc]=='1') {
                dfs(a, rr, cc);
            } 
        }
    }
    int numIslands(vector<vector<char>>& a) {
        int cnt=0;
        for(int i=0;  i<a.size() ; ++i) {
            for(int j=0 ; j<a[0].size() ; ++j) {
                if(a[i][j] == '1') dfs(a, i, j), cnt++;
            }
        }
        return cnt;
    }
};
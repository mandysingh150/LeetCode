int dir[]={-1,0,1,0,-1};
class Solution {
public:
    int dfs(vector<vector<int>>& a, int row, int col) {
        int ans = 1;
        a[row][col]=0;
        for(int i=0 ; i<4 ; ++i) {
            int r=row+dir[i], c=col+dir[i+1];
            if(r>=0 and r<a.size() and c>=0 and c<a[0].size() and a[r][c]) {
                ans += dfs(a, r, c);
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& a) {
        int mx=0;
        for(int i=0 ; i<a.size() ; ++i) {
            for(int j=0 ; j<a[0].size(); ++j) {
                mx = max(mx, (a[i][j] ? dfs(a, i, j) : 0));
            }
        }
        return mx;
    }
};
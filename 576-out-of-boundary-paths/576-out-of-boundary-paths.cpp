int dir[]={-1,0,1,0,-1}, dp[51][51][51];
#define mod int(1e9+7)
class Solution {
public:
    int rows, cols;
    int h(int row, int col, int moves_left) {
        if(row<0 or col<0 or row==rows or col==cols) {
            return 1;
        }
        if(moves_left == 0) {
            return 0;
        }
        if(dp[row][col][moves_left] != -1) {
            return dp[row][col][moves_left];
        }
        int ans = 0;
        for(int i=0 ; i<4 ; ++i) {
            int r=row+dir[i], c=col+dir[i+1];
            ans = (ans + h(r, c, moves_left-1))%mod;
        }
        return dp[row][col][moves_left] = ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        rows=m;
        cols=n;
        memset(dp, -1, sizeof(dp));
        return h(startRow, startColumn, maxMove);
    }
};
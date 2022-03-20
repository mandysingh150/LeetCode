class Solution {
public:
    int help(vector<vector<int>> &a, int col) {
        int m=a.size(), n=a[0].size();
        for(int row=0 ; row<m and col>=0 and col<n ; ++row) {
            if(a[row][col]==1) {
                if(col+1>=n or a[row][col+1]==-1)
                    return -1;
                else
                    col++;
            }
            else {
                if(col-1<0 or a[row][col-1]==1)
                    return -1;
                else
                    col--;
            }
        }
        return (col==n ? -1 : col);
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> v;
        for(int col=0 ; col<grid[0].size() ; ++col) {
            v.push_back(help(grid, col));
        }
        return v;
    }
};
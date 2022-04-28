int dir[] = {-1,0,1,0,-1};
class Solution {
public:
    vector<vector<int>> v;
    void isPossible(vector<vector<int>>& h, int row, int col, int val) {
        for(int k=0 ; k<4 ; ++k) {
            int x = dir[k]+row, y = dir[k+1]+col;
            if(x>=0 and x<h.size() and y>=0 and y<h[0].size() and abs(h[x][y]-h[row][col])<=val and !v[x][y]) {
                v[x][y] = 1;
                isPossible(h, x, y, val);
            }
        }
    }
    int minimumEffortPath(vector<vector<int>>& he) {
        int l=0, h=INT_MAX, ans;
        while(l<=h) {
            int mid = (l+h)>>1;
            
            v = vector<vector<int>>(he.size(), vector<int>(he[0].size(), 0));
            v[0][0] = 1;
            isPossible(he, 0, 0, mid);
            
            if(v[he.size()-1][he[0].size()-1]) {
                h=mid-1;
                ans = mid;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};
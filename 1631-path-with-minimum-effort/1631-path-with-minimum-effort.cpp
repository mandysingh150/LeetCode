int dir[] = {-1,0,1,0,-1};

class Solution {
public:
    bool isPossible(vector<vector<int>>& h, int val) {
        queue<pair<int,int>> q;
        vector<vector<int>> v(h.size(), vector<int>(h[0].size(), 0));
        q.push({0,0});
        v[0][0] = 1;
        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            if(row==h.size()-1 and col==h[0].size()-1)
                return 1;
            
            for(int k=0 ; k<4 ; ++k) {
                int x = dir[k]+row, y = dir[k+1]+col;
                if(x>=0 and x<h.size() and y>=0 and y<h[0].size() and abs(h[x][y]-h[row][col])<=val and !v[x][y]) {
                    v[x][y] = 1;
                    q.push({x,y});
                }
            }
        }
        return 0;
    }
    int minimumEffortPath(vector<vector<int>>& he) {
        int l=0, h=INT_MAX, ans;
        while(l<=h) {
            int mid = (l+h)>>1;
            if(isPossible(he, mid)) {
                h=mid-1;
                ans = mid;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};
#define tup tuple<int,int,int>
class Solution {
public:
    int maximumMinutes(vector<vector<int>>& a) {
        auto find_corner_three = [&](bool is_fire) -> vector<int> {
            vector<vector<int>> v(a.size(), vector<int>(a[0].size(), INT_MAX));
            queue<pair<int,int>> q;
            int m=a.size(), n=a[0].size();
            int dir[]={-1,0,1,0,-1};
            if(is_fire) {
                for(int i=0 ; i<a.size() ; ++i) {
                    for(int j=0 ; j<a[0].size() ; ++j) {
                        if(a[i][j] == 1) {
                            v[i][j] = 0;
                            q.push({i, j});
                        }
                    }
                }
            }
            else {
                v[0][0] = 0;
                q.push({0, 0});
            }
            while(!q.empty()) {
                auto [row, col] = q.front();
                q.pop();
                
                for(int i=0 ; i<4 ; ++i) {
                    int r=row+dir[i], c=col+dir[i+1];
                    if(r>=0 and r<m and c>=0 and c<n and a[r][c]==0 and v[row][col]+1<v[r][c]) {
                        v[r][c] = 1 + v[row][col];
                        q.push({r, c});
                    }
                }
            }
            return vector<int>{v[m-1][n-1], v[m-2][n-1], v[m-1][n-2]};
        };
        auto fire=find_corner_three(1), person=find_corner_three(0);
        if(fire[0] == INT_MAX and person[0] != INT_MAX)
            return 1e9;
        int diff=fire[0]-person[0];
        if(person[0] != INT_MAX and diff>=0) {
            return diff - (fire[1]-person[1]<=diff and fire[2]-person[2]<=diff);
        }
        return -1;
    }
};
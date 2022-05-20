class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        if(a[0][0] or a[a.size()-1][a[0].size()-1])
            return 0;
        vector<vector<int>> v(a.size(), vector<int>(a[0].size(), 0));
        v[0][0] = 1;
        for(int i=0 ; i<a.size() ; ++i) {
            for(int j=0 ; j<a[0].size() ; ++j) {
                if(a[i][j]==0) {
                    if(i-1>=0 and j-1>=0 and !a[i-1][j] and !a[i][j-1])
                        v[i][j] = v[i-1][j] + v[i][j-1];
                    else if(i-1>=0 and !a[i-1][j])
                        v[i][j] = v[i-1][j];
                    else if(j-1>=0 and !a[i][j-1])
                        v[i][j] = v[i][j-1];
                }
            }
        }
        return v[a.size()-1][a[0].size()-1];
    }
};
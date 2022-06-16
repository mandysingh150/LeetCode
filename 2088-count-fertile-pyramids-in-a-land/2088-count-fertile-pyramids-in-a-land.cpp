class Solution {
public:
    int countPyramids(vector<vector<int>>& a) {
        int m=a.size(), n=a[0].size();
        auto count_pyramids = [&](vector<vector<int>> &v) -> int {
            int ans=0;
            for(int i=1 ; i<m ; ++i) {
                for(int j=1 ; j<n-1 ; ++j) {
                    if(v[i][j] == 1) {
                        v[i][j] = 1 + min(v[i-1][j-1], min(v[i-1][j], v[i-1][j+1]));
                        ans += v[i][j]-1;
                    }
                }
            }
            return ans;
        };
        vector<vector<int>> dp(a.begin(), a.end());
        reverse(dp.begin(), dp.end());
        return count_pyramids(a) + count_pyramids(dp);
    }
};
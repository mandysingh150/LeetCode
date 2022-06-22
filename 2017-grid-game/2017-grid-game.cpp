class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long row_1_sum = accumulate(begin(grid[0]), end(grid[0]), 0ll), row_2_sum=0ll, ans=LLONG_MAX;
        for(int i=0 ; i<grid[0].size() ; ++i) {
            row_1_sum -= grid[0][i];
            ans = min(ans, max(row_1_sum, row_2_sum));
            row_2_sum += grid[1][i];
        }
        return ans;
    }
};
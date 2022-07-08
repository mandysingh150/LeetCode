int dp[102][22][102];
class Solution {
public:
    int x;
    int h(vector<int>& houses, vector<vector<int>>& cost, int in, int prev_color, int ngs) {
        if(in == houses.size()) {
            if(ngs == x) {
                return 0;
            }
            return INT_MAX-1e7;
        }
        if(ngs > x)
            return INT_MAX-1e7;
        if(dp[in][prev_color][ngs] != -1) {
            return dp[in][prev_color][ngs];
        }
        int ans = INT_MAX-1e7;
        if(houses[in] == 0) {
            for(int i=1 ; i<=cost[0].size() ; ++i) {
                if(i == prev_color) {
                    ans = min(ans, cost[in][i-1] + h(houses, cost, in+1, i, ngs));
                }
                else {
                    ans = min(ans, cost[in][i-1] + h(houses, cost, in+1, i, ngs+1));
                }
            }
        }
        else {
            if(houses[in] == prev_color) {
                ans = h(houses, cost, in+1, prev_color, ngs);
            }
            else {
                ans = h(houses, cost, in+1, houses[in], ngs+1);
            }
        }
        return dp[in][prev_color][ngs] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        x=target;
        memset(dp, -1, sizeof(dp));
        int ans = h(houses, cost, 0, 0, 0);
        return ans >= INT_MAX-1e7 ? -1 : ans;
    }
};
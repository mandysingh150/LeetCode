int dp[1001][101][2];
class Solution {
public:
    long long h(vector<int> &a, int in, int k, bool buy) {
        if(in == a.size() or (k==0 and buy)) return 0ll;
        if(dp[in][k][buy] != -1) return dp[in][k][buy];
        return dp[in][k][buy] = max(0ll + h(a, in+1, k, buy), 0ll + (buy ? -1ll : 1ll)*a[in] + h(a, in+1, k-buy, !buy));
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return h(prices, 0, k, 1);
    }
};
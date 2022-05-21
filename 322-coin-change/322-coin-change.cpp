class Solution {
public:
    vector<vector<int>> dp;
    int h(vector<int> &coins, int in, int x) {
        if(x == 0)
            return 0;
        if(in == coins.size() or x < 0)
            return INT_MAX-10000;
        if(dp[in][x] != -1)
            return dp[in][x];
        int a = h(coins, in+1, x), b=INT_MAX;
        if(x >= coins[in])
            b = 1+min(h(coins, in, x-coins[in]), h(coins, in+1, x-coins[in]));
        return dp[in][x] = min(a, b);
    }
    int coinChange(vector<int>& coins, int amount) {
        dp = vector<vector<int>>(coins.size(), vector<int>(amount+1, -1));
        sort(begin(coins), end(coins));
        int ans = h(coins, 0, amount);
        return ans>=INT_MAX-10000 ? -1 : ans;
    }
};
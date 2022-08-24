class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        long long N = stations.size();
        vector<long long> dp(N + 1, 0);
        dp[0] = startFuel;
        for (int i = 0; i < N; ++i)
            for (int t = i; t >= 0; --t)
                if (dp[t] >= stations[i][0])
                    dp[t+1] = max(dp[t+1], 0ll + dp[t] + stations[i][1]);

        for (int i = 0; i <= N; ++i) if(dp[i] >= target) return i;
        return -1;
    }
};
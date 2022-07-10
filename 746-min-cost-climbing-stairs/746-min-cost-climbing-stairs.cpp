class Solution {
public:
    int minCostClimbingStairs(vector<int>& a) {
        int dp[1001], n=a.size();
        dp[n-1]=a[n-1];
        dp[n-2]=a[n-2];
        for(int i=n-3 ; i>=0 ; --i) {
            dp[i] = a[i] + min(dp[i+1], dp[i+2]);
        }
        return min(dp[0], dp[1]);
    }
};
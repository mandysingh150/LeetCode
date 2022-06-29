class Solution {
public:
    bool dp[201][20001];
    bool canPartition(vector<int>& a) {
        int sum = accumulate(begin(a), end(a), 0ll);
        if(sum&1) return 0;
        sum >>= 1;
        for(int i=0 ; i<=a.size() ; ++i) {
            for(int j=0; j<=sum ; ++j) {
                if(i==0 and j==0) {
                    dp[i][j] = 1;
                }
                else if(i==0 or j==0) {
                    dp[i][j] = 0;
                }
                else {
                    if(a[i-1] <= j) {
                        dp[i][j] = dp[i-1][j] or dp[i-1][j-a[i-1]];
                    }
                    else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        return dp[a.size()][sum];
    }
};
#define mod int(1e9+7)
class Solution {
public:
//     int kInversePairs(int n, int k) {
//         int totalPairs = (n*(n-1))/2;
//         if(k==0 || k==totalPairs)
//             return 1;
//         if(k>totalPairs)
//             return 0;
//         if(k==1 || k==totalPairs-1)
//             return n-1;
        
        
        
//         return 0;
//     }
    
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            dp[i][0] = 1;
            for(int j = 1; j <= k; ++j){
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod;
                if(j - i >= 0){
                    dp[i][j] = (dp[i][j] - dp[i-1][j-i] + mod) % mod; 
                    //It must + mod, If you don't know why, you can check the case 1000, 1000
                }
            }
        }
        return dp[n][k];
    }
};
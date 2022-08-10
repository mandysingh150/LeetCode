#define mod int(1e9+7)
class Solution {
public:
    int countVowelPermutation(int n) {
        // 0=a, 1=e, 2=i, 3=o, 4=u
        vector<vector<int>> dp(20005, vector<int>(5, 1));
        vector<vector<int>> mp{{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {0}};
        
        for(int i=n-2 ; i>=0 ; --i) {
            for(int j=0 ; j<5 ; ++j) {
                dp[i][j] = 0;
                for(auto in: mp[j]) {
                    // dp[i][j] = (1ll * dp[i][j] * dp[i+1][in])%mod;
                    dp[i][j] = (0ll + dp[i][j] + dp[i+1][in])%mod;
                }
            }
        }
        int sum = 0;
        for(int i=0 ; i<5 ; ++i) {
            sum = (0ll + sum + dp[0][i]) % mod;
        }
        return sum;
    }
};
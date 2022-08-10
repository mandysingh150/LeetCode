#define mod int(1e9+7)
class Solution {
public:
    int countVowelPermutation(int n) {
        // 0=a, 1=e, 2=i, 3=o, 4=u
        int dp[2][5], mp[6][6] = {{1, 1}, {2, 0, 2}, {4, 0, 1, 3, 4}, {2, 2, 4}, {1, 0}};        
        for(int i=n-1 ; i>=0 ; --i) {
            if(i == n-1) {
                for(int j=0 ; j<5 ; ++j) {
                    dp[i%2][j] = 1;
                }
            }
            else {
                for(int j=0 ; j<5 ; ++j) {
                    dp[i%2][j] = 0;
                    for(int in=1 ; in<=mp[j][0] ; ++in) {
                        dp[i%2][j] = (0ll + dp[i%2][j] + dp[(i+1)%2][mp[j][in]])%mod;
                    }
                }
            }
        }
        return accumulate(dp[0], dp[0]+5, 0ll)%mod;
    }
};
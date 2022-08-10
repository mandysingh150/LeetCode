#define mod int(1e9+7)
class Solution {
public:
    int countVowelPermutation(int n) {
        // 0=a, 1=e, 2=i, 3=o, 4=u
        int dp[2][5];
        for(int i=0 ; i<2 ; ++i) {
            for(int j=0 ; j<5 ; ++j) {
                dp[i][j] = 1;
            }
        }
        int mp[6][6] = {{1, 1}, {2, 0, 2}, {4, 0, 1, 3, 4}, {2, 2, 4}, {1, 0}};
        
        for(int i=n-2 ; i>=0 ; --i) {
            for(int j=0 ; j<5 ; ++j) {
                dp[i%2][j] = 0;
                for(int in=1 ; in<=mp[j][0] ; ++in) {
                    dp[i%2][j] = (0ll + dp[i%2][j] + dp[(i+1)%2][mp[j][in]])%mod;
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
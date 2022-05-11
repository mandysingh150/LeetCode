int dp[51][5];
string s = "aeiou";
class Solution {
public:
    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    int countVowelStrings(int n, int in=0) {
        if(n==1 or in==4)
            return 5-in;
        if(dp[n][in] != -1)
            return dp[n][in];
        int ans = 0;
        for(int i=in ; i<5 ; ++i)
            ans += countVowelStrings(n-1, i);
        return dp[n][in] = ans;
    }
};
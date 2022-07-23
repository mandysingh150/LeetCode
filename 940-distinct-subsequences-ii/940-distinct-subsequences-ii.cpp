#define mod int(1e9+7)
class Solution {
public:
    int distinctSubseqII(string &s) {
        int dp[2005], last_occured[26];
        memset(last_occured, -1, sizeof(last_occured));
        dp[0]=1;
        for(int i=1 ; i<=s.size() ; ++i) {
            dp[i] = ((2ll * dp[i-1])%mod - (last_occured[s[i-1]-'a']>=0 ? dp[last_occured[s[i-1]-'a']] : 0))%mod;
            last_occured[s[i-1]-'a'] = i-1;
        }
        if(--dp[s.size()] < 0)
            dp[s.size()] += mod;
        return dp[s.size()];
    }
};
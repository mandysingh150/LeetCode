#define mod (int(1e9+7))
class Solution {
public:
    int dp[100001], mp;
    int h(string &s, int i, int mp[]) {
        // if (i==s.size()), it means we want to get the answer of only the last digit
        // now, the number of text message combinations (for only last digit) = 1
        if(i == s.size())
            return 1;
        if(dp[i] != -1)
            return dp[i];
        
        long long ans=0;
        for(int in=0 ; in<mp[s[i]-'0'] and in+i<s.size() and s[in+i]==s[i] ; ++in) {
            ans = (ans + h(s, i+in+1, mp))%mod;            
        }
        return dp[i] = ans;
    }
    int countTexts(string &s) {
        int mp[10] = {0,0,3,3,3,3,3,4,3,4};
        memset(dp, -1, sizeof(dp));
        return h(s, 0, mp);
    }
};
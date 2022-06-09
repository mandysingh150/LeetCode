#define mod int(1e9+7)
class Solution {
public:
    int countTexts(string &s) {
        int mx[] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
        
        vector<int> dp(s.size()+1, 0);
        dp[s.size()]=1;
        for(int i=s.size()-1 ; i>=0 ; --i) {
            for(int j=0 ; j<mx[s[i]-'0'] and i+j<s.size() and s[i+j]==s[i] ; ++j) {
                dp[i] += dp[i+j+1];
                dp[i] %= mod;
            }
        }
        return dp[0];
    }
};
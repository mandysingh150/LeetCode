int dp[2005][2005];
class Solution {
public:
    bool isMatch(string &s, string &p, int in_s, int in_p) {
        if(in_p >= p.size()) {
            return in_s >= s.size();
        }
        if(dp[in_s][in_p] != -1) {
            return dp[in_s][in_p];
        }
        if(in_s<s.size() and (s[in_s]==p[in_p] or p[in_p]=='?')) {
            return dp[in_s][in_p] = isMatch(s, p, in_s+1, in_p+1);
        }
        return dp[in_s][in_p] = (p[in_p]=='*' and (isMatch(s, p, in_s, in_p+1) or in_s<s.size() and isMatch(s, p, in_s+1, in_p)));
    }
    bool isMatch(string &s, string &p) {
        memset(dp, -1, sizeof(dp));
        return isMatch(s, p, 0, 0);
    }
};
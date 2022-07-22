int dp[21][31];
class Solution {
public:
    bool isMatch(string &s, string &p, int in_s, int in_p) {
        if(in_p >= p.size()) {
            return in_s >= s.size();
        }
        if(dp[in_s][in_p] != -1) {
            return dp[in_s][in_p];
        }
        bool ans = (in_s<s.size() and (s[in_s]==p[in_p] or p[in_p]=='.'));
        if(in_p+1<p.size() and p[in_p+1]=='*') {
            return dp[in_s][in_p] = (isMatch(s, p, in_s, in_p+2) or (ans and isMatch(s, p, in_s+1, in_p)));
        }
        return dp[in_s][in_p] = ans and isMatch(s, p, in_s+1, in_p+1);
    }
    bool isMatch(string &s, string &p) {
        memset(dp, -1, sizeof(dp));
        return isMatch(s, p, 0, 0);
    }
};
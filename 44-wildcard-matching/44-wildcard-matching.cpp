int dp[2005][2005];
class Solution {
public:
    bool h(string &s, string &p, int in_s, int in_p) {
        if(in_p >= p.size())
            return in_s >= s.size();

        if(dp[in_s][in_p] != -1)
            return dp[in_s][in_p];
        
        if(in_s<s.size() and (p[in_p]==s[in_s] or p[in_p]=='?'))
            return h(s, p, in_s+1, in_p+1);
        
        if(p[in_p] == '*')
            return dp[in_s][in_p] = h(s, p, in_s, in_p+1) or in_s<s.size() and h(s, p, in_s+1, in_p);
            
        return 0;
    }
    bool isMatch(string &s, string &p) {
        memset(dp, -1, sizeof(dp));
        return h(s, p, 0, 0);
    }
};
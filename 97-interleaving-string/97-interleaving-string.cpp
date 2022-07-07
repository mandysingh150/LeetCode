int dp[101][101];
class Solution {
public:
    bool h(string &s1, int i1, string &s2, int i2, string &s3, int i3) {
        if(i3 == s3.size())
            return 1;
        if(dp[i1][i2] != -1)
            return dp[i1][i2];

        bool ans=0;
        if(s1[i1] == s3[i3])
            ans |= h(s1, i1+1, s2, i2, s3, i3+1);
        if(s2[i2] == s3[i3])
            ans |= h(s1, i1, s2, i2+1, s3, i3+1);
        return dp[i1][i2] = ans;
    }
    bool isInterleave(string &s1, string &s2, string &s3) {
        if(s1.size()+s2.size() != s3.size())
            return 0;
        memset(dp, -1, sizeof(dp));
        return h(s1, 0, s2, 0, s3, 0);
    }
};
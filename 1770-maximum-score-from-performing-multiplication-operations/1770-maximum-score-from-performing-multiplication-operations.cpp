class Solution {
public:
    vector<vector<int>> dp;
    int h(vector<int> &a, vector<int> &b, int in, int si, int ei) {
        if(in == b.size())
            return 0;
        if(dp[in][si] != INT_MIN) return dp[in][si];
        return dp[in][si] = max(a[si]*b[in] + h(a, b, in+1, si+1, ei), a[ei]*b[in] + h(a, b, in+1, si, ei-1));
    }
    int maximumScore(vector<int>& a, vector<int>& mul) {
        dp = vector<vector<int>>(1005, vector<int>(1005, INT_MIN));
        return h(a, mul, 0, 0, a.size()-1);
    }
};
class Solution {
public:
    int dp[301][301];
    int h(vector<int> &a, int si, int ei) {
        if(si > ei) {
            return 0;
        }
        if(dp[si][ei] != -1)
            return dp[si][ei];
        int mx=0;
        for(int i=si ; i<=ei ; ++i) {
            mx = max(mx, (si-1<0 ? 1 : a[si-1]) * a[i] * (ei+1==a.size() ? 1 : a[ei+1]) + h(a, si, i-1) + h(a, i+1, ei));
        }
        return dp[si][ei] = mx;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return h(nums, 0, nums.size()-1);
    }
};
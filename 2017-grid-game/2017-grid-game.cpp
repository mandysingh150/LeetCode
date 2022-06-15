class Solution {
public:
    long long gridGame(vector<vector<int>>& a) {
        long long top_sum = accumulate(begin(a[0]), end(a[0]), 0ll), bottom_sum=0, ans=LLONG_MAX;
        for(int i=0 ; i<a[0].size() ; ++i) {
            top_sum -= a[0][i];
            ans = min(ans, max(top_sum, bottom_sum));
            bottom_sum += a[1][i];
        }
        return ans;
    }
};
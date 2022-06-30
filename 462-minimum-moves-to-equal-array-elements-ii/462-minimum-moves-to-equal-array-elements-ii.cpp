class Solution {
public:
    int minMoves2(vector<int>& a) {
        sort(begin(a), end(a));
        long long left_sum=0, right_sum=accumulate(begin(a), end(a), 0ll), ans=INT_MAX, n=a.size();
        for(int i=0 ; i<a.size() ; ++i) {
            right_sum -= a[i];
            ans = min(ans, (1ll*a[i]*i - left_sum) + (right_sum - 1ll*a[i]*(n-1-i)));
            left_sum += a[i];
        }
        return ans;
    }
};
class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size(), left=0, right=n-1, ans=0, right_mx=a[right], left_mx=a[left];
        while(left<right) {
            right_mx = max(a[right], right_mx);
            left_mx = max(a[left], left_mx);
            ans += min(left_mx, right_mx) - (a[left] <= a[right] ? a[left++] : a[right--]);
        }
        return ans;
    }
};
#define ll long long
class Solution {
public:
    long long find_sum(long long n) {
        return (n*(n+1))>>1;
    }
    int maxValue(int n, int index, int maxSum) {
        ll l=1, h=maxSum, ans;
        while(l<=h) {
            ll mid = (l+h)>>1;
            
            // processing
            ll sum = mid;
            ll left = find_sum(mid-1) + (mid > index ? -find_sum(mid-index-1) : index-mid+1);
            ll right = find_sum(mid-1) + (mid >= n-index ? -find_sum(mid-(n-index)) : n-index-mid);
            sum += left+right;
            
            if(sum <= maxSum) {
                ans = mid;
                l=mid+1;
            }
            else
                h = mid-1;
        }
        return ans;
    }
};
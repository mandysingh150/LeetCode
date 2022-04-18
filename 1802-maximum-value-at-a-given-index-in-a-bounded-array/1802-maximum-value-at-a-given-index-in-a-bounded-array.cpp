#define ll long long
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        auto find_sum = [](long long n) { return n*(n+1)>>1; };
        
        ll l=1, h=maxSum, ans;
        while(l<=h) {
            ll mid = (l+h)>>1;
            
            // sum of current index
            ll sum = mid +
			    // left side sum
			    (find_sum(mid-1) + (mid > index ? -find_sum(mid-index-1) : index-mid+1)) + 
			    // right side sum
			    (find_sum(mid-1) + (mid >= n-index ? -find_sum(mid-(n-index)) : n-index-mid));
            
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
#define ll long long
class Solution {
public:
    int maxFrequency(vector<int>& a, int k) {
        ll l=2, h=a.size(), ans=1;
        vector<long long> pre(1,0);
        sort(begin(a), end(a));
        for(auto i: a) pre.push_back(pre.back()+i);
        while(l<=h) {
            ll mid = (l+h)>>1;
            
            ll minOperations=LLONG_MAX;
            for(int i=mid ; i<=a.size() ; ++i)
                minOperations = min(minOperations, mid*a[i-1] - (pre[i]-pre[i-mid]));
            
            if(minOperations <= k) {
                ans = mid;
                l=mid+1;
            }
            else
                h=mid-1;
        }
        return ans;
    }
};
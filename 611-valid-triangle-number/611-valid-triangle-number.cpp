class Solution {
public:
    int triangleNumber(vector<int>& a) {
        sort(begin(a), end(a));
        int cnt=0, n=a.size();
        for(int i=0 ; i<n ; ++i) {
            for(int j=i+1 ; j<n ; ++j) {
                int l=j+1, h=n-1, ans=j;
                while(l<=h) {
                    int mid=(l+h)>>1;
                    if(a[mid] >= a[i]+a[j])
                        h=mid-1;
                    else
                        ans=mid, l=mid+1;
                }
                cnt += ans-j;
            }
        }
        return cnt;
    }
};
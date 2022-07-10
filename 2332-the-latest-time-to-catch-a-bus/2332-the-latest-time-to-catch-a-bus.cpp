class Solution {
public:
    bool check(vector<int>& b, vector<int>& p, int cap, int mid) {
        for(int i=0, j=0 ; i<b.size() ; ++i) {
            int cnt=0;
            while(j<p.size() and cnt<cap and mid>p[j] and p[j]<=b[i]) {
                cnt++;
                j++;
            }
            if(cnt<cap and mid<=b[i])
                return 1;
        }
        return 0;
    }
    int latestTimeCatchTheBus(vector<int>& b, vector<int>& p, int cap) {
        sort(begin(b), end(b));
        sort(begin(p), end(p));
        int l=1, h=INT_MAX, ans;
        while(l<=h) {
            int mid = (0ll+l+h)>>1;
            if(check(b, p, cap, mid)) {
                ans = mid;
                l=mid+1;
            }
            else {
                h=mid-1;
            }
        }
        int in = lower_bound(begin(p), end(p), ans) - begin(p);
        while(in!=p.size() and in>=0 and p[in]==ans) {
            in--;
            ans--;
        }
        return ans;
    }
};
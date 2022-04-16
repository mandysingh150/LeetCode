class Solution {
public:
    bool help(vector<int> &v, int skip, int tot) {
        tot--;  // one ball is placed on v[i]
        int i=0;
        vector<int>::iterator it;
        while(tot and (it=lower_bound(v.begin()+i, v.end(), v[i]+skip))!=v.end()) {
            i = it-v.begin();
            tot--;
        }
        return tot==0;
    }
    int maxDistance(vector<int>& a, int m) {
        sort(a.begin(), a.end());
        int l=1, h=a.back()-l, ans=1;
        while(l<=h) {
            int mid = (l+h)/2;
            if(help(a, mid, m)) {
                ans = mid;
                l = mid+1;
            }
            else
                h = mid-1;
        }
        return ans;
    }
};
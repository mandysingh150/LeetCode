class Solution {
public:
    int minSubArrayLen(int x, vector<int>& a) {
        if(accumulate(begin(a), end(a), 0) < x)
            return 0;
        vector<long long> pre{0};
        for(auto i: a) {
            pre.push_back(pre.back()+i);
        }
        int l=1, h=a.size(), ans;
        while(l<=h) {
            int mid = (l+h)>>1;
            bool t=0;
            for(int i=0 ; i<=a.size()-mid ; ++i) {
                if(pre[i+mid]-pre[i] >= x) {
                    t=1;
                    break;
                }
            }
            if(t) {
                ans = mid;
                h=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return ans;
    }
};
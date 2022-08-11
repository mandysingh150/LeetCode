class Solution {
public:
    bool check(vector<int>& t, vector<int>& w, int p, int s, int mid) {
        multiset<int> mst(end(w)-mid, end(w));
        int need=0;
        for(int i=mid-1 ; i>=0 ; --i) {
            auto it = prev(end(mst));
            if(*it < t[i]) {
                it = mst.lower_bound(t[i] - s);
                if(it == end(mst) or ++need > p) {
                    return 0;
                }
            }
            mst.erase(it);
        }
        return mst.size()==0;
    }
    int maxTaskAssign(vector<int>& t, vector<int>& w, int p, int s) {
        sort(begin(t), end(t));
        sort(begin(w), end(w));
        
        int l=0, h=min(t.size(), w.size()), ans=0;
        while(l<=h) {
            int mid = (l+h)>>1;
            if(check(t, w, p, s, mid)) {
                l = mid+1;
                ans = mid;
            }
            else {
                h = mid-1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool help(vector<int> &v, int skip, int tot) {
        int pos = v[0];
        for(int i=1 ; i<v.size() ; ++i) {
            if(v[i] - pos >= skip) {
                --tot;
                pos = v[i];
            }
        }
        return tot<=1;
    }
    int maxDistance(vector<int>& a, int m) {
        sort(a.begin(), a.end());
        int l=1, h=a.back()-l, ans=1;
        while(l<=h) {
            int mid = (l+h)/2;
            if(help(a, mid, m))
                ans = mid, l = mid+1;
            else
                h = mid-1;
        }
        return ans;
    }
};
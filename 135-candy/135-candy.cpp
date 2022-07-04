class Solution {
public:
    int candy(vector<int>& a) {
        vector<int> l_to_r(a.size(), 1), r_to_l(a.size(), 1);
        int n=a.size();
        for(int i=1 ; i<n ; ++i) {
            if(a[i-1] < a[i]) {
                l_to_r[i] = 1 + l_to_r[i-1];
            }
        }
        for(int i=n-2 ; i>=0 ; --i) {
            if(a[i] > a[i+1]) {
                r_to_l[i] = 1 + r_to_l[i+1];
            }
        }
        int ans=0;
        for(int i=0 ; i<n ; ++i) {
            ans += max(l_to_r[i], r_to_l[i]);
        }
        return ans;
    }
};
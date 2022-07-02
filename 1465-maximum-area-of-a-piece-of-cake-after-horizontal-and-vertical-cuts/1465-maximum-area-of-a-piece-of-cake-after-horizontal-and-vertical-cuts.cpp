class Solution {
public:
    int maxArea(int ht, int wid, vector<int>& hc, vector<int>& vc) {
        int h_mx=0, v_mx=0, cnt=0;
        for(auto a: {hc, vc}) {
            int val = 0, t=(cnt ? wid : ht);
            sort(begin(a), end(a));
            for(int i=0 ; i<=a.size() ; ++i) {
                if(i == 0) {
                    val = max(val, a[i]);
                }
                else if(i == a.size()) {
                    val = max(val, t-a[i-1]);
                }
                else {
                    val = max(val, a[i]-a[i-1]);
                }
            }
            (cnt==1 ? v_mx : h_mx) = val;
            cnt++;
        }
        return (1ll*h_mx*v_mx)%(int(1e9+7));
    }
};
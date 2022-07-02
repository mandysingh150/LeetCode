class Solution {
public:
    int maxArea(int ht, int wid, vector<int>& hc, vector<int>& vc) {
        long long h_mx=0, v_mx=0, cnt=0;
        hc.push_back(ht);
        vc.push_back(wid);
        for(auto a: {hc, vc}) {
            sort(begin(a), end(a));
            int val = a[0], t=(cnt ? wid : ht);
            for(int i=1 ; i<a.size() ; ++i) {
                val = max(val, a[i]-a[i-1]);
            }
            (cnt==1 ? v_mx : h_mx) = val;
            cnt++;
        }
        return (h_mx*v_mx)%(int(1e9+7));
    }
};
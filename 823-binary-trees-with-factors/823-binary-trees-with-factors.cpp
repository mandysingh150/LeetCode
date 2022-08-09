#define ll long long
#define mod int(1e9+7)
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& a) {
        sort(a.begin(),a.end());
        unordered_map<int,ll> mp;
        long long ans = 0ll;
        for(int i=0 ; i<a.size() ; ++i) {
            int t=1;
            for(int j=i-1 ; j>=0 ; --j) {
                if(a[i]%a[j]==0) {
                    int val = a[i]/a[j];
                    if(val>1 and mp.count(val)) {
                        t = (t + (1ll * (mp[a[j]]%mod) * (mp[val]%mod))) % mod;
                    }
                }
            }
            mp[a[i]] += t;
            ans = (0ll + ans + t) % mod;
        }
        return ans;
    }
};
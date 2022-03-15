class Solution {
public:
    int countOrders(int n) {
        long long val = 1, mod = 1e9+7;
        for(int i=2 ; i<=n ; ++i)
            val = (val*(2*i-1)*i)%mod;
        return val;
    }
};
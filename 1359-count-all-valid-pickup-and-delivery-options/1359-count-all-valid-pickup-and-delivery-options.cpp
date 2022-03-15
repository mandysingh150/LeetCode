#define mod ((int)(1e9+7))
class Solution {
public:
    int h(int n) {
        if(n<=0)
            return 0;
        if(n==1)
            return 1;
        return (1ll*n*(2*n-1)*h(n-1))%mod;
    }
    int countOrders(int n) {
        return h(n)%mod;
    }
};
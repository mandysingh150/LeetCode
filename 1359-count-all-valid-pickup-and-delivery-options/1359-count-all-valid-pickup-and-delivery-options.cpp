class Solution {
public:
    int countOrders(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        return (1ll*n*(2*n-1)*countOrders(n-1))%((int)(1e9+7));
    }
};
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long q = 1ll*dividend/divisor;
        if(q < INT_MIN) return INT_MIN;
        if(q > INT_MAX) return INT_MAX;
        return q;
    }
};
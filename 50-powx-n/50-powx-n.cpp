class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 or x==1.0)
            return 1.0;
        long long l=n;
        if(l<0) {
            l=-l;
            x=1/x;
        }
        return l&1 ? x*myPow(x*x, l/2) : myPow(x*x, l/2);
    }
};
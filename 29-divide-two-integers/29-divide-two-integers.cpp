class Solution {
public:
    int divide(int A, int B) {
        if(A == INT_MIN and B == -1)
            return INT_MAX;
        
        long long a=abs(A), b=abs(B), ans=0, x;
        while(a >= b) {
            for(x=0 ; a >= ((b << x) << 1) ; ++x);
            ans += (1<<x);
            a -= (b<<x);
        }
        return (A>0)==(B>0) ? ans : -ans;
    }
};
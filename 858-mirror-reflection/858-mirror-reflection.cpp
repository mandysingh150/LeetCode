class Solution {
public:
    int mirrorReflection(int p, int q) {
        // (2m-1) * p = (2n-1) * q  -> 1
        // 2n * p = q               -> 0
        // p = 2n * q               -> 2
        
        while(p%2==0 and q%2==0) {
            p>>=1;
            q>>=1;
        }
        return 1 - p%2 + q%2;
    }
};
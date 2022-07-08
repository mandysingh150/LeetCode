class Solution {
public:
    int uniquePaths(int m, int n) {
        long long N = m+n-2, R=m-1, ans=1;
        for(int i=1 ; i<=R ; ++i) {
            ans *= (N-R+i);
            ans /= i;
        }
        // for(int i=1 ; i<=R ; ++i) {
        //     ans /= i;
        // }
        return ans;
    }
};
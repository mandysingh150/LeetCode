class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for(int i=1 ; i<=n ; ++i) s += i+'0';
        while(--k) next_permutation(begin(s), end(s));
        return s;
    }
};
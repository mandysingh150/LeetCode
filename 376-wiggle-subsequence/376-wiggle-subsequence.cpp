class Solution {
public:
    int dp[1001][1010][2];
    int h(vector<int> &a, int in, int prev, bool inc) {
        if(in == a.size()) {
            return 0;
        }
        if(dp[in][prev+2][inc] != -1) {
            return dp[in][prev+2][inc];
        }
        int a1 = h(a, in+1, prev, inc), a2=0;
        if(inc) {
            if(prev < a[in]) {
                a2 = 1 + h(a, in+1, a[in], !inc);
            }
        }
        else {
            if(prev > a[in]) {
                a2 = 1 + h(a, in+1, a[in], !inc);
            }
        }
        return dp[in][prev+2][inc] = max(a1, a2);
    }
    int wiggleMaxLength(vector<int>& a) {
        memset(dp, -1, sizeof(dp));
        return max(h(a, 0, -1, 1), h(a, 0, 1001, 0));
    }
};
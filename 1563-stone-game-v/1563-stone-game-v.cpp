class Solution {
public:
    int dp[502][502];
    int help(vector<int> &a, int si, int ei) {
        if(si >= ei)
            return 0;
        if(dp[si][ei] != -1)
            return dp[si][ei];
        
        // break the vector at index 'i' so that the parts become [si, i] and [i+1, ei]
        int val=0;
        for(int i=si ; i<ei ; ++i) {
            int sum1 = a[i]-a[si-1], sum2 = a[ei]-a[i];
            if(sum1 >= sum2)
                val = max(val, sum2 + help(a, i+1, ei));
            if(sum2 >= sum1)
                val = max(val, sum1 + help(a, si, i));
        }
        return dp[si][ei] = val;
    }
    int stoneGameV(vector<int>& a) {
        memset(dp, -1, sizeof(dp));
        vector<int> pre={0};
        for(auto i: a) pre.push_back(pre.back() + i);
        return help(pre, 1, a.size());
    }
};
class Solution {
public:
    int dp[20005];
    bool help(vector<int> &a, int in) {
        if(in == a.size()) return 1;
        if(dp[in] != -1) return dp[in];
        for(int i=0 ; in+i<=min(int(a.size()-1), in+3) ; ++i) {
            if((i==0 and ((a[in]>>7)&1)==0) or 
               (i==1 and ((a[in]>>7)&1)==1 and ((a[in]>>6)&1)==1 and ((a[in]>>5)&1)==0 and 
                    ((a[in+1]>>7)&1)==1 and ((a[in+1]>>6)&1)==0) or
               (i==2 and ((a[in]>>7)&1)==1 and ((a[in]>>6)&1)==1 and ((a[in]>>5)&1)==1 and 
                    ((a[in]>>4)&1)==0 and ((a[in+1]>>7)&1)==1 and ((a[in+1]>>6)&1)==0 and       
                    ((a[in+2]>>7)&1)==1 and ((a[in+2]>>6)&1)==0) or
               (i==3 and ((a[in]>>7)&1)==1 and ((a[in]>>6)&1)==1 and ((a[in]>>5)&1)==1 and 
                    ((a[in]>>4)&1)==1 and ((a[in]>>3)&1)==0 and 
                    ((a[in+1]>>7)&1)==1 and ((a[in+1]>>6)&1)==0 and
                    ((a[in+2]>>7)&1)==1 and ((a[in+2]>>6)&1)==0 and 
                    ((a[in+3]>>7)&1)==1 and ((a[in+3]>>6)&1)==0)) {
                
                if(help(a, in+i+1)) {
                    return dp[in] = 1;
                }
            }
        }
        return dp[in] = 0;
    }
    bool validUtf8(vector<int>& data) {
        memset(dp, -1, sizeof(dp));
        return help(data, 0);
    }
};
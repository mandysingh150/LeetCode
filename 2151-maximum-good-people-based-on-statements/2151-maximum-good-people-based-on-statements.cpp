class Solution {
public:
    int maximumGood(vector<vector<int>>& a) {
        int n=a.size(), ans=0;
        for(int i=0 ; i<(1<<n) ; ++i) {
            int found=1;
            for(int j=0 ; j<n ; ++j) {
                if(i&(1<<j)) {
                    for(int k=0 ; k<n ; ++k) {
                        if(j!=k) {
                            if(a[j][k]==2)
                                continue;
                            if(a[j][k] != ((i&(1<<k)) ? 1 : 0)) {
                                found=0;
                                break;
                            }
                        }
                    }
                    if(!found)
                        break;
                }
            }
            if(found)
                ans = max(ans, __builtin_popcount(i));
        }
        return ans;
    }
};
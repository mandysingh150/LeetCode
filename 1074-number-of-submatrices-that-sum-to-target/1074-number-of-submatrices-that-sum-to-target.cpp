class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& a, int x) {
        int prefix_sum_2d[102][102]={0}, m=a.size(), n=a[0].size();
        for(int i=1 ; i<=m ; ++i) {
            for(int j=1 ; j<=n ; ++j) {
                prefix_sum_2d[i][j] = a[i-1][j-1] + prefix_sum_2d[i-1][j] + prefix_sum_2d[i][j-1] - prefix_sum_2d[i-1][j-1];
            }
        }
        int ans=0;
        for(int r1=1 ; r1<=m ; ++r1) {
            for(int r2=r1 ; r2<=m ; ++r2) {
                map<int,int> mp;
                mp[0]++;
                for(int c=1 ; c<=n ; ++c) {
                    int sum = prefix_sum_2d[r2][c] - prefix_sum_2d[r1-1][c];
                    if(mp.count(sum - x)) {
                        ans += mp[sum - x];
                    }
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};
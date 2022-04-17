class Solution {
public:
    pair<int,int> count_2_5(int val) {
        int cnt_2=0, cnt_5=0;
        while(val%5==0)
            val/=5, cnt_5++;
        while(val%2==0)
            val/=2, cnt_2++;
        return {cnt_2, cnt_5};
    }
    int maxTrailingZeros(vector<vector<int>>& a) {
        int m=a.size(), n=a[0].size(), ans=0;
        // {cnt_2, cnt_5}
        vector<vector<pair<int,int>>> ltor(m,vector<pair<int,int>>(n+1)), ttob(m+1,vector<pair<int,int>>(n));
        for(int i=0 ; i<m ; ++i) {
            for(int j=0 ; j<n ; ++j) {
                auto [cnt_2, cnt_5] = count_2_5(a[i][j]);
                ltor[i][j+1] = {ltor[i][j].first+cnt_2, ltor[i][j].second+cnt_5};
                ttob[i+1][j] = {ttob[i][j].first+cnt_2, ttob[i][j].second+cnt_5};
            }
        }
        for(int i=0 ; i<m ; ++i) {
            for(int j=0 ; j<n ; ++j) {
                pair<int,int> t1 = ttob[i+1][j], t2 = {ttob[m][j].first-ttob[i][j].first, ttob[m][j].second-ttob[i][j].second};
                pair<int,int> l1 = ltor[i][j], l2 = {ltor[i][n].first-ltor[i][j+1].first, ltor[i][n].second-ltor[i][j+1].second};
                
                ans = max(ans, min(t1.first+l1.first, t1.second+l1.second));
                ans = max(ans, min(t1.first+l2.first, t1.second+l2.second));
                ans = max(ans, min(t2.first+l1.first, t2.second+l1.second));
                ans = max(ans, min(t2.first+l2.first, t2.second+l2.second));
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& a) {
        sort(begin(a), end(a), [](vector<int> &c, vector<int> &d) {
            if(c[0] == d[0])
                return c[1] > d[1];
            return c[0] < d[0];
        });
        
        vector<int> LIS;
        LIS.push_back(a[0][1]);
        for(int i=0 ; i<a.size() ; ++i) {
            auto index = lower_bound(begin(LIS), end(LIS), a[i][1]) - begin(LIS);
            if(index >= LIS.size())
                LIS.push_back(a[i][1]);
            else
                LIS[index] = a[i][1];
        }        
        return LIS.size();
    }
};
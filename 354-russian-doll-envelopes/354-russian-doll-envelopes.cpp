class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& a) {
        // sorting in ASCENDING order of widths and DESCENDING order of heights
        sort(begin(a), end(a), [](vector<int> &c, vector<int> &d) {
            if(c[0] == d[0])
                return c[1] > d[1];
            return c[0] < d[0];
        });
        
        vector<int> lis;
        lis.push_back(a[0][1]);
        for(int i=0 ; i<a.size() ; ++i) {
            auto index = lower_bound(begin(lis), end(lis), a[i][1]) - begin(lis);
            if(index >= lis.size())
                lis.push_back(a[i][1]);
            else
                lis[index] = a[i][1];
        }        
        return lis.size();
    }
};
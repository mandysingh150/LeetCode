class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [](vector<int> &c, vector<int>&d) {
            return c[0]<d[0];
        });
        vector<vector<int>> v{a[0]};
        for(int i=1 ; i<a.size() ; ++i) {
            auto t = v.back();
            if(a[i][0]>=t[0] and a[i][0]<=t[1]) {
                v.back() = {t[0], max(a[i][1], t[1])};
            }
            else {
                v.push_back(a[i]);
            }
        }
        return v;
    }
};
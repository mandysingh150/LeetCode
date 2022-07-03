class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& ni) {
        a.push_back(ni);
        sort(begin(a), end(a));
        
        // merge now
        vector<vector<int>> v{a[0]};
        for(int i=1 ; i<a.size() ; ++i) {
            auto t = v.back();
            if(a[i][0]>=t[0] and a[i][0]<=t[1]) {
                v.back() = {t[0], max(t[1], a[i][1])};
            }
            else {
                v.push_back(a[i]);
            }
        }
        return v;
    }
};
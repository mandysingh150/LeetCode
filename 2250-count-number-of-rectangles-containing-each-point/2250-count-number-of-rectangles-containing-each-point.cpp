class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& r, vector<vector<int>>& p) {
        vector<int> v, h[101];
        for(auto i: r) {
            h[i[1]].push_back(i[0]);
        }
        for(int i=0 ; i<101 ; ++i) {
            sort(h[i].begin(), h[i].end());
        }
        for(auto i: p) {
            int ans = 0;
            for(int k=i[1] ; k<=100 ; ++k) {
                ans += h[k].end() - lower_bound(h[k].begin(), h[k].end(), i[0]);
            }
            v.push_back(ans);
        }
        return v;
    }
};
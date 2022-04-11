class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> v;
        for(auto i: grid) for(auto j: i) v.push_back(j);
        k = k%v.size();
        reverse(v.begin(), v.end());
        reverse(v.begin(), v.begin()+k);
        reverse(v.begin()+k, v.end());
        int cnt=0;
        for(auto &i: grid) for (auto &j: i) j=v[cnt++];
        return grid;
    }
};
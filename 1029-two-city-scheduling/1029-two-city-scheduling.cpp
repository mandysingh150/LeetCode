class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& a) {
        vector<pair<int,int>> v;
        for(int i=0 ; i<a.size() ; ++i)
            v.push_back({a[i][0]-a[i][1], i});
        sort(begin(v), end(v));
        int val=0;
        for(int i=0 ; i<a.size() ; ++i)
            val += i<a.size()/2 ? a[v[i].second][0] : a[v[i].second][1];
        return val;
    }
};
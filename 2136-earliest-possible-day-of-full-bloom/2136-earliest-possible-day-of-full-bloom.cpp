class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        vector<pair<int,int>> v;
        for(int i=0 ; i<pt.size() ; ++i) {
            v.push_back({gt[i], pt[i]});
        }
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        int plant_time=0, grow_time=0;
        for(int i=0 ; i<v.size() ; ++i) {
            plant_time += v[i].second;
            grow_time = max(grow_time, plant_time + v[i].first);
        }
        return grow_time;
    }
};
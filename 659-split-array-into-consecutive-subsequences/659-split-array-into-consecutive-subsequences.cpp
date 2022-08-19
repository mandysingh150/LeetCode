class Solution {
public:
    bool isPossible(vector<int>& nums) {
        multiset<pair<int,int>> mst;
        for(auto i: nums) {
            auto it = mst.lower_bound({i-1,0});
            if(it == mst.end() or it->first >= i) {
                mst.insert({i,1});
            }
            else {
                auto [val, len] = *it;
                mst.erase(it);
                mst.insert({i, len+1});
            }
        }
        for(auto i: mst) {
            if(i.second < 3) {
                return 0;
            }
        }
        return 1;
    }
};
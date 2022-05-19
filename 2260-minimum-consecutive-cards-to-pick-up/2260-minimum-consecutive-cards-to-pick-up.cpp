class Solution {
public:
    int minimumCardPickup(vector<int>& a) {
        unordered_map<int,vector<int>> mp;
        for(int i=0 ; i<a.size() ; ++i) {
            mp[a[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto [key, val]: mp) {
            for(int i=0 ; i<val.size()-1 ; ++i) {
                if(val[i+1]-val[i]+1 < ans) {
                    ans = val[i+1]-val[i]+1;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
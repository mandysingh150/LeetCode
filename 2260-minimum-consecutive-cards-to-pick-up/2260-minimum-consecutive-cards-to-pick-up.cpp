class Solution {
public:
    int minimumCardPickup(vector<int>& a) {
        unordered_map<int,int> mp;
        int ans = INT_MAX;
        for(int i=0 ; i<a.size() ; ++i) {
            if(mp.count(a[i]))
                if(i-mp[a[i]]+1 < ans)
                    ans = i-mp[a[i]]+1;
            mp[a[i]] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
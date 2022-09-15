class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        sort(begin(a), end(a));
        unordered_map<int,int> mp;
        vector<int> v;
        for(auto i: a) mp[i]++;
        for(auto i: a) {
            if(mp[i] > 0) {
                mp[i]--;
                if(mp[i*2]==0)
                    return vector<int>{};
                mp[i*2]--;
                v.push_back(i);
            }
        }
        return v;
    }
};
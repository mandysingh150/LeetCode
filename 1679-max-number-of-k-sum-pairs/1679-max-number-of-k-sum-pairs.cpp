class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int cnt=0;
        for(auto i: nums) mp[i]++;
        for(auto &[key, val]: mp) {
            if(key == k-key) {
                cnt += val/2;
            }
            else if(mp.count(k-key)) {
                int mn = min(val, mp[k-key]);
                cnt += mn;
                mp[key] -= mn;
                mp[k-key] -= mn;
            }
        }
        return cnt;
    }
};
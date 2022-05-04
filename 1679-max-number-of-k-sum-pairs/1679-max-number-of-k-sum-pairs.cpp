class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int cnt=0;
        for(auto i: nums) mp[i]++;
        for(auto i: nums) {
            if(mp.count(i) and mp.count(k-i)) {
                if(i == k-i) {
                    if(mp[i]>=2)
                        cnt++;
                }
                else {
                    if(mp[i]>=1 and mp[k-i]>=1)
                        cnt++;
                }
                if(--mp[i] == 0)
                    mp.erase(i);
                if(--mp[k-i] == 0)
                    mp.erase(k-i);
            }
        }
        return cnt;
    }
};
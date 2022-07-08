class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        int mx=0;
        for(auto i: nums) mp[i]=1;
        for(int i=0 ; i<nums.size() ; ++i) {
            if(mp[nums[i]]) {
                int cnt=1, l=nums[i]-1, r=nums[i]+1;
                mp[nums[i]]=0;
                while(mp.count(l)) mp[l]=0, --l, cnt++;
                while(mp.count(r)) mp[r]=0, ++r, cnt++;
                mx = max(mx, cnt);
            }
        }
        return mx;
    }
};
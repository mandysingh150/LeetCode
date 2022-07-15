class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xr=0;
        for(auto i: nums) xr^=i;
        return xr;
    }
};
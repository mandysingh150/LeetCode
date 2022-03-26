class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, h=nums.size()-1;
        while(l<=h) {
            int md = (l+h)>>1;
            if(nums[md] == target)
                return md;
            else if(nums[md] < target)
                l=md+1;
            else
                h=md-1;
        }
        return -1;
    }
};
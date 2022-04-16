class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1)
            return 0;
        if(n==2)
            return (nums[1]>nums[0] ? 1 : 0);
        
        for(int i=0 ; i<n ; ++i) {
            if((i==0 and nums[i]>nums[i+1]) or (i==n-1 and nums[i]>nums[i-1]))
                return i;
            else if(nums[i]>nums[i+1] and nums[i]>nums[i-1])
                return i;
        }
        return -1;
    }
};
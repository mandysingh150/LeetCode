class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=nums[0], freq=1;
        for(int i=1 ; i<nums.size() ; ++i) {
            freq += (nums[i] == ele ? 1 : -1);
            if(freq == 0) {
                ele = nums[i];
                freq=1;
            }
        }
        return ele;   
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=nums[0], freq=1;
        for(int i=1 ; i<nums.size() ; ++i) {
            nums[i] == ele ? freq++ : freq--;
            if(freq == 0) {
                ele = nums[i];
                freq=1;
            }
        }
        return ele;   
    }
};
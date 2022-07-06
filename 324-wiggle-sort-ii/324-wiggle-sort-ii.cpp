class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<int> ans(nums.size());
        int j=nums.size()-1;
        for(int i=1 ; i<nums.size() ; i+=2) {
            ans[i] = nums[j];
            j--;
        }
        for(int i=0 ; i<nums.size() ; i+=2) {
            ans[i] = nums[j];
            j--;
        }
        nums=ans;
    }
};
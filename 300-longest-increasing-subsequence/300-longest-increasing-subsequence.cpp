class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // O(n^2) time cmoplexity
        // vector<int> dp(nums.size(), 1);
        // for(int i=0 ; i<nums.size() ; ++i) {
        //     for(int j=0 ; j<i ; ++j) {
        //         if(nums[i] > nums[j])
        //             dp[i] = max(dp[i], dp[j]+1);
        //     }
        // }
        // return *max_element(dp.begin(), dp.end());
        
        // O(n) time complexity
        vector<int> v;
        for(auto i: nums) {
            if(v.empty() or v.back()<i)
                v.push_back(i);
            else
                *lower_bound(v.begin(), v.end(), i) = i;
        }
        return v.size();
    }
};
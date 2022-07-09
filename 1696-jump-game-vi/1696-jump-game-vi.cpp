class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        multiset<int, greater<int>> s;
        vector<int> dp(nums.size());
        dp.front() = nums.front();
        s.insert(nums[0]);
        for(int i=1 ; i<nums.size() ; ++i) {
            if(i>k)
                s.erase(s.find(dp[i-k-1]));
            dp[i] = *s.begin() + nums[i];
            s.insert(dp[i]);
        }
        return dp.back();
    }
};
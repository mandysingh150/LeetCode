class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0, mx=INT_MIN;
        for(auto i: nums) {
            sum += i;
            mx = max(sum, mx);
            if(sum < 0) {
                sum = 0;
            }
        }
        return mx;
    }
};
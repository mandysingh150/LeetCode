class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1, h=*max_element(nums.begin(), nums.end()), ans;
        while(l<=h) {
            int mid = (l+h)>>1;
            int cnt=0;
            for(auto i: nums) if(i>mid) cnt+=((i-1)/mid);
            if(cnt <= maxOperations)
                ans = mid, h=mid-1;
            else
                l=mid+1;
        }
        return ans;
    }
};
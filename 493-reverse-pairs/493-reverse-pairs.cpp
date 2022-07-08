class Solution {
public:
    int merge_sort(vector<int> &a, int si, int ei) {
        if(si >= ei)
            return 0;
        int mid = (si+ei)>>1;
        int cnt = merge_sort(a, si, mid) + merge_sort(a, mid+1, ei);
        int i=si, j=mid+1;
        while(i<=mid and j<=ei) {
            if(a[i] > 2ll*a[j]) {
                cnt += mid-i+1;
                j++;
            }
            else {
                i++;
            }
        }
        sort(begin(a)+si, begin(a)+ei+1);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size()-1);
    }
};
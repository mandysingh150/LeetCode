class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size();
        int left_max=0, right_max=0, left=0, right=n-1, ans=0;
        while(left <= right) {
            if(a[left] <= a[right]) {
                if(a[left] > left_max) {
                    left_max = a[left];
                }
                else {
                    ans += left_max-a[left];
                }
                left++;
            }
            else {
                if(a[right] > right_max) {
                    right_max = a[right];
                }
                else {
                    ans += right_max-a[right];
                }
                right--;
            }
        }
        return ans;
    }
};
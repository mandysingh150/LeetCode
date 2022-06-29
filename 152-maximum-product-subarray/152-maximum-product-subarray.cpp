class Solution {
public:
    int maxProduct(vector<int>& a) {
        int left_to_right=1, right_to_left=1, ans=INT_MIN, n=a.size();
        for(int i=0 ; i<n ; ++i) {
            left_to_right *= a[i];
            right_to_left *= a[n-1-i];
            ans = max(ans, max(left_to_right, right_to_left));
            if(left_to_right == 0) {
                left_to_right = 1;
            }
            if(right_to_left == 0) {
                right_to_left = 1;
            }
        }
        return ans;
    }
};
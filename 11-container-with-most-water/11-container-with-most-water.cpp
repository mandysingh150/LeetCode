#define ff first
#define ss second
class Solution {
public:
    int maxArea(vector<int>& a) {
        // {start, end}
        int l=0, r=a.size()-1, ans=0;
        while(l < r) {
            ans = max(ans, (r-l)*min(a[l], a[r]));
            if(a[l] < a[r]) l++;
            else r--;
        }
        return ans;
    }
};
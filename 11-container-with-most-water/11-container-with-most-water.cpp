class Solution {
public:
    int maxArea(vector<int>& a) {
        int i=0, j=a.size()-1, ans=0;
        while(i<j) {
            ans = max(ans, min(a[j], a[i])*(j-i));
            if(a[i] < a[j])
                ++i;
            else
                --j;
        }
        return ans;
    }
};
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
        int si=0, ei=0, sum=0, ans=INT_MAX;
        while(ei<a.size()) {
            sum += a[ei];
            while(sum >= target) {
                ans = min(ans, ei-si+1);
                sum -= a[si];
                si++;
            }
            ei++;
        }
        return (ans==INT_MAX ? 0 : ans);
    }
};
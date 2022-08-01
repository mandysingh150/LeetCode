class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int sz) {
        int a[1001]={0}, mx=0;
        for(auto i: boxTypes) {
            a[i[1]] += i[0];
            mx = max(mx, i[1]);
        }
        int ans=0;
        for(int i=mx ; i>=0 and sz>0 ; --i) {
            int mn = min(sz, a[i]);
            ans += i*mn;
            sz -= mn;
        }
        return ans;
    }
};
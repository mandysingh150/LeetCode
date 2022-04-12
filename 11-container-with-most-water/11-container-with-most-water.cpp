class Solution {
public:
    int maxArea(vector<int>& a) {
        int si=0, ei=a.size()-1, mx=0;
        while(si<ei) {
            mx = max(mx, min(a[si], a[ei])*(ei-si));
            if(a[si] <= a[ei])
                si++;
            else
                ei--;
        }
        return mx;
    }
};
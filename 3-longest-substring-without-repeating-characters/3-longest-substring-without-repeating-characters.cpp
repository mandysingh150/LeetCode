class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        int si=0, ei=0, mx=0;
        int a[256]={0};
        while(ei<s.size()) {
            while(a[s[ei]]) {
                a[s[si]] = 0;
                si++;
            }
            a[s[ei]] = 1;
            ei++;
            mx = max(mx, ei-si);
        }
        return mx;
    }
};
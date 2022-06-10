class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        int si=0, ei=0, mx=0;
        unordered_set<int> st;
        while(ei<s.size()) {
            while(st.count(s[ei])) {
                st.erase(s[si]);
                si++;
            }
            st.insert(s[ei]);
            ei++;
            mx = max(mx, ei-si);
        }
        return mx;
    }
};
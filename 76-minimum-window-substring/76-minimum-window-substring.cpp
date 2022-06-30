class Solution {
public:
    string minWindow(string &s, string &t) {
        int si=0, ei=0;
        pair<int,int> ans={-1,INT_MAX};
        unordered_set<char> st;
        int a[256]={0};
        for(auto i: t) {
            a[i]++;
            st.insert(i);
        }
        int cnt=0;
        while(ei < s.size()) {
            if(st.count(s[ei])) {
                if(--a[s[ei]] == 0)
                    cnt++;
                while(cnt == st.size()) {
                    if(ei-si+1 < ans.second) {
                        ans = {si, ei-si+1};
                    }
                    if(st.count(s[si]) and ++a[s[si]] > 0)
                        cnt--;
                    si++;
                }
            }
            ei++;
        }
        return ans.first==-1 ? "" : s.substr(ans.first, ans.second);
    }
};
class Solution {
public:
    string minWindow(string &s, string &t) {
        // {start_index, length}
        pair<int,int> ans={-1,INT_MAX};
        int si=0, ei=0, cnt=0;
        unordered_set<int> mp;
        int f[256]={0};
        for(auto i: t) {
            mp.insert(i);
            f[i]++;
        }
        while(ei<s.size()) {
            if(mp.count(s[ei])) {
                if(--f[s[ei]] == 0) {
                    cnt++;
                }
                while(cnt == mp.size()) {
                    if(ei-si+1 < ans.second)
                        ans = {si, ei-si+1};
                    if(mp.count(s[si]) and ++f[s[si]] == 1) 
                        cnt--;
                    si++;
                }
            }
            ei++;
        }
        return ans.first==-1 ? "" : s.substr(ans.first, ans.second);
    }
};
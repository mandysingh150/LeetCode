class Solution {
public:
    bool isAnagram(string &s, string &t) {
        if(s.size() != t.size()) return 0;
        int cnt[26]={0};
        for(int i=0 ; i<s.size() ; ++i) cnt[s[i]-'a']++;
        for(int i=0 ; i<t.size() ; ++i) if(--cnt[t[i]-'a'] < 0) return 0;
        return 1;
    }
};
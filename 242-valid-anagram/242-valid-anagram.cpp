class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return 0;
        int a[256]={0};
        for(auto i: s) a[i]++;
        for(auto i: t) if(--a[i] < 0) return 0;
        return 1;
    }
};
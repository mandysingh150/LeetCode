class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int freq[26]={0};
        vector<string> v;
        for(auto &s: words2) {
            int t[26]={0};
            for(auto i: s) {
                freq[i-'a'] = max(freq[i-'a'], ++t[i-'a']);
            }
        }
        for(auto &s: words1) {
            int t[26]={0};
            for(auto i: s) t[i-'a']++;
            bool ok=1;
            for(int i=0 ; i<26 ; ++i) {
                if(t[i] < freq[i]) {
                    ok=0;
                    break;
                }
            }
            if(ok) {
                v.push_back(s);
            }
        }
        return v;
    }
};
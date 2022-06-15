class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string &a, string &b) {
            return a.size()<b.size();
        });
        unordered_map<string,int> mp;
        for(int i=0 ; i<words.size() ; ++i) {
            mp[words[i]] = 1;
        }
        int mx=1;
        for(auto str: words) {
            for(int i=0 ; i<str.size() ; ++i) {
                string t = str.substr(0, i) + str.substr(i+1);
                if(mp.count(t)) {
                    mp[str] = 1+mp[t];
                    mx = max(mx, mp[str]);
                }
            }
        }
        return mx;
    }
};
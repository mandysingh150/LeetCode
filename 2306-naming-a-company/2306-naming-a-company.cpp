class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans=0;
        unordered_set<string> mp[26];
        for(auto i: ideas) {
            mp[i[0]-'a'].insert(i.substr(1));
        }
        for(char c1='a' ; c1<='z' ; ++c1) {
            for(char c2=c1+1 ; c2<='z' ; ++c2) {
                int cnt_same=0;
                for(auto i: mp[c2-'a']) {
                    if(mp[c1-'a'].count(i)) {
                        cnt_same++;
                    }
                }
                ans += 2 * (mp[c1-'a'].size()-cnt_same) * (mp[c2-'a'].size()-cnt_same);
            }
        }
        return ans;
    }
};
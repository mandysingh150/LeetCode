class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans=0;
        unordered_map<char,unordered_set<string>> mp;
        for(auto i: ideas) {
            mp[i[0]].insert(i.substr(1));
        }
        for(char c1='a' ; c1<='z' ; ++c1) {
            for(char c2='a' ; c2<='z' ; ++c2) {
                if(c1 != c2) {
                    int cnt_same=0;
                    for(auto i: mp[c2]) {
                        if(mp[c1].count(i)) {
                            cnt_same++;
                        }
                    }
                    ans += (mp[c1].size()-cnt_same) * (mp[c2].size()-cnt_same);
                }
            }
        }
        return ans;
    }
};
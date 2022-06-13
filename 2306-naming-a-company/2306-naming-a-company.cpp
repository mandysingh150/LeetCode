class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        vector<unordered_set<string>> v(26);
        
        for(auto &i: ideas) {
            v[i[0]-'a'].insert(i.substr(1));
        }
        
        for(int i=0 ; i<25 ; ++i) {
            for(int j=i+1 ; j<26 ; ++j) {
                int count_same = 0;
                for(auto &str: v[i]) {
                    count_same += v[j].count(str);
                }
                ans += (2 * (v[i].size() - count_same) * (v[j].size() - count_same));
            }
        }
        return ans;
    }
};
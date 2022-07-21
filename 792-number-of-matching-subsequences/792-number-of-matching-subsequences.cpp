class Solution {
public:
    int numMatchingSubseq(string &s, vector<string>& w) {
        vector<pair<int,int>> a[128];
        for(int i=0 ; i<w.size() ; ++i) {
            a[w[i][0]].push_back({i, 0});
        }
        for(int i=0 ; i<s.size() ; ++i) {
            auto processing = a[s[i]];
            a[s[i]].clear();
            for(auto [word_index, char_index]: processing) {
                a[w[word_index][char_index+1]].push_back({word_index, char_index+1});
            }
        }
        // as strings are terminated by null character, our answer will be the number of strings in which we have reached the NULL character
        return a[0].size();
    }
};
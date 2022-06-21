class Solution {
public:
    int h(int i, vector<string> &a, vector<int> &val, int mp[]) {
        if(i == a.size()) {
            return 0;
        }
        int _1 = h(i+1, a, val, mp);
        bool will_accomodate=1;
        for(auto ch: a[i]) if(--mp[ch-'a'] < 0) will_accomodate = 0;
        int _2 = will_accomodate ? val[i] + h(i+1, a, val, mp) : 0;
        for(auto ch: a[i]) ++mp[ch-'a'];
        return max(_1, _2);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> val(words.size());
        for(int i=0 ; i<words.size() ; ++i) {
            for(auto ch: words[i]) {
                val[i] += score[ch-'a'];
            }
        }
        int mp[26]={0};
        for(auto i: letters) {
            mp[i-'a']++;
        }
        return h(0, words, val, mp);
    }
};
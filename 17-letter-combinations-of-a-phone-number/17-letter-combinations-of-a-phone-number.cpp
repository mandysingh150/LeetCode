class Solution {
public:
    string a[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> v;
    void h(string &s, int i, string &t) {
        if(i == s.size()) {
            v.push_back(t);
            return;
        }
        for(auto ch: a[s[i]-'0']) {
            t.push_back(ch);
            h(s, i+1, t);
            t.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        v.clear();
        if(digits.empty())
            return v;
        string t;
        h(digits, 0 ,t);
        return v;
    }
};
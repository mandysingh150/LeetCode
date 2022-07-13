class Solution {
public:
    vector<vector<string>> ans;
    bool is_palindrome(string &s) {
        for(int i=0 , j=s.size()-1 ; i<j ; ++i, --j) {
            if(s[i] != s[j])
                return 0;
        }
        return 1;
    }
    void h(string &s, int in, vector<string> &v) {
        if(in == s.size()) {
            ans.push_back(v);
        }
        string t="";
        for(int i=in ; i<s.size() ; ++i) {
            t.push_back(s[i]);
            if(is_palindrome(t)) {
                v.push_back(t);
                h(s, i+1, v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string &s) {
        vector<string> v;
        h(s, 0, v);
        return ans;
    }
};
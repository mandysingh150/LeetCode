class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string &pattern) {
        vector<string> a;
        vector<int> v;
        int p[26]={0}, sz=0;
        for(auto i: pattern) {
            if(p[i-'a'] == 0) {
                p[i-'a'] = ++sz;
            }
            v.push_back(p[i-'a']);
        }
        for(auto i: words) {
            memset(p, 0, sizeof(p));
            sz=0;
            bool ok=1;
            for(int j=0 ; j<i.size() ; ++j) {
                if(p[i[j]-'a'] == 0) {
                    p[i[j]-'a'] = ++sz;
                }
                if(p[i[j]-'a'] != v[j]) {
                    ok=0;
                    break;
                }
            }
            if(ok) a.push_back(i);
        }
        return a;
    }
};
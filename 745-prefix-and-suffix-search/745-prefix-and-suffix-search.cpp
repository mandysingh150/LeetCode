class WordFilter {
public:
    unordered_map<string,int> mp;
    WordFilter(vector<string>& s) {
        for(int i=0 ; i<s.size() ; ++i) {
            string word = s[i];
            int sz=word.size();
            for(int j=0 ; j<sz ; ++j) {
                string prefix = word.substr(0, j+1);
                for(int k=0 ; k<sz ; ++k) {
                    string suffix = word.substr(k, sz-k);
                    mp[prefix + " " + suffix] = i;
                }
            }
        }
    }
    
    int f(string p, string s) {
        string t = p + " " + s;
        return mp.count(t) ? mp[t] : -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
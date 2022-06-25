class WordFilter {
public:
    unordered_map<string,int> mp;
    WordFilter(vector<string>& words) {
        for(int i=0 ; i<words.size() ; ++i) {
            for(int j=1 ; j<=words[i].size() ; ++j) {
                string pre = words[i].substr(0, j);
                for(int k=1 ; k<=words[i].size() ; ++k) {
                    mp[pre + " " + words[i].substr(words[i].size()-k)] = i;
                }
            }
        }
    }
    
    int f(string pref, string suff) {
        string s = pref + " " + suff;
        return mp.count(s) ? mp[s] : -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
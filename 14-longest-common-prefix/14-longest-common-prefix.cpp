class Solution {
public:
    class trienode {
    public:
        int cnt=0;
        trienode* children[26];
        trienode() {
            cnt=0;
            for(int i=0 ; i<26 ; ++i) {
                children[i]=nullptr;
            }
        }
    };
    
    void add_word(trienode *r, string &s, int in) {
        if(in == s.size()) {
            return;
        }
        if(!r->children[s[in]-'a']) {
            r->children[s[in]-'a'] = new trienode();
        }
        r->children[s[in]-'a']->cnt++;
        add_word(r->children[s[in]-'a'], s, in+1);
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        trienode *root = new trienode();
        for(auto &i: strs) add_word(root, i, 0);
        string ans="";
        for(int i=0 ; i<26 ; ++i) {
            if(root->children[i]) {
                if(root->children[i]->cnt < strs.size()) {
                    return ans;
                }
                ans.push_back('a'+i);
                root = root->children[i];
                i=-1;
            }
        }
        return ans;
    }
};
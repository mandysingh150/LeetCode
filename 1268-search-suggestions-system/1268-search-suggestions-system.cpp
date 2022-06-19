class TrieNode {
public:
    bool is_end;
    TrieNode* children[26];
    TrieNode() {
        is_end=0;
        for(int i=0 ; i<26 ; ++i) {
            children[i] = nullptr;
        }
    }
};

class Solution {
public:
    vector<vector<string>> ans;
    void add(string &word, int in, TrieNode* r) {
        if(in == word.size()) {
            r->is_end = 1;
            return;
        }
        
        if(!r->children[word[in]-'a']) {
            r->children[word[in]-'a'] = new TrieNode();
        }
        add(word, in+1, r->children[word[in]-'a']);
    }
    
    void find_3(TrieNode *r, string &s, vector<string> &v) {
        if(r->is_end and v.size()<3) {
            v.push_back(s);
        }
        for(int i=0 ; i<26 ; ++i) {
            if(r->children[i]) {
                s.push_back(i+'a');
                find_3(r->children[i], s, v);
                s.pop_back();
                if(v.size() == 3)
                    return;                
            }
        }
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string &word) {
        ans.clear();
        TrieNode *root = new TrieNode();
        
        // build the Trie
        for(auto i: products) {
            add(i, 0, root);
        }
        
        // find similar words
        string s;
        for(int i=0 ; i<word.size() ; ++i) {
            if(!root->children[word[i]-'a'])
                root->children[word[i]-'a'] = new TrieNode();
            root = root->children[word[i]-'a'];
            
            vector<string> v;
            s += word[i];
            find_3(root, s, v);
            ans.push_back(v);
        }
        return ans;
    }
};
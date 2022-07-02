#define n nullptr

class node {
public:
    vector<node*> children;
    bool ending;
    node() : children(26, n), ending(0) {}
};

class Trie {
public:
    node *root;
    Trie() {
        root = new node();
    }
    
    void insertHelper(node *root, string &word, int i) {
        if(i == word.size()) {
            root->ending = 1;
            return;
        }        
        if(root->children[word[i]-'a'] == n)
            root->children[word[i]-'a'] = new node();;
        insertHelper(root->children[word[i]-'a'], word, i+1);
    }
    
    void insert(string word) {
        insertHelper(root, word, 0);
    }
    
    bool searchHelper(node *root, string &word, int i) {
        if(i == word.size())
            return root->ending;
        if(root->children[word[i]-'a'] == n)
            return 0;
        return searchHelper(root->children[word[i]-'a'], word, i+1);
    }
    
    bool search(string word) {
        return searchHelper(root, word, 0);
    }
    
    bool startsWithHelper(node *root, string &word, int i) {
        if(i == word.size())
            return 1;
        if(root->children[word[i]-'a'] == n)
            return 0;
        return startsWithHelper(root->children[word[i]-'a'], word, i+1);
    }
    
    bool startsWith(string word) {
        return startsWithHelper(root, word, 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
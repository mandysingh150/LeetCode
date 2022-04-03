class Encrypter
{
public:
    unordered_map<char, string> kv;
    unordered_map<string,int> dict;
    Encrypter(vector<char> &keys, vector<string> &values, vector<string> &dictionary) {
        for (int i = 0; i < size(keys); i++)
            kv[keys[i]] = values[i];
        for(auto str: dictionary) {
            string temp="";
            for (int i = 0;  i < str.size(); i++) 
                temp += kv[str[i]];
            dict[temp]++;
        }            
    }
    
    string encrypt(string w) {
        string s = "";
        for (int i = 0; i < size(w); i++)
            s += kv[w[i]];
        return s;
    }
    
    int decrypt(string w) {
        return dict[w];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
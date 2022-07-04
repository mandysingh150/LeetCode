class Solution {
public:
    int calculate(string &s) {
        string temp="";
        for(auto i: s) 
            if(i != ' ') 
                temp += i;
        s = temp;
        vector<string> v;
        for(int i=0 ; i<s.size() ; ++i) {
            if(isdigit(s[i])) {
                string t="";
                while(i<s.size() and isdigit(s[i])) {
                    t += s[i];
                    i++;
                }
                v.push_back(t);
                i--;
            }
            else {
                v.push_back(string(1, s[i]));
            }
        }
        vector<string> a;
        // division and multiplication
        for(int i=0 ; i<v.size() ; ++i) {
            if(v[i][0] == '*' or v[i][0] == '/') {
                int v1 = stoi(a.back());
                int v2 = stoi(v[i+1]);
                a.back() = to_string(v[i][0] == '*' ? v1*v2 : v1/v2);
                i++;
            }
            else {
                a.push_back(v[i]);
            }
        }
        v = a;
        a.clear();
        
        // addition and subtraction
        for(int i=0 ; i<v.size() ; ++i) {
            if(v[i][0] == '+' or v[i][0] == '-') {
                int v1 = stoi(a.back());
                int v2 = stoi(v[i+1]);
                a.back() = to_string(v[i][0] == '+' ? v1+v2 : v1-v2);
                i++;
            }
            else {
                a.push_back(v[i]);
            }
        }
        return stoi(a[0]);
    }
};
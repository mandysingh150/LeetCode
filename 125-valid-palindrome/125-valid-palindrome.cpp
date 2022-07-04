class Solution {
public:
    bool isPalindrome(string &s) {
        string t="";
        for(auto i: s) {
            if(isalnum(i)) {
                if(islower(i) or (i>='0' and i<='9'))
                    t.push_back(i);
                else if(i>='A' and i<='Z') {
                    t.push_back(i+32);
                }
            }
        }
        s = t;
        reverse(begin(s), end(s));
        return s.compare(t)==0;
    }
};
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int in1=0, in2=0;
        for(int i=0 ; i<s.size() ; ++i) {
            if(s[i] == '#') {
                if(in1 > 0)
                    in1--;
            }                
            else {
                s[in1] = s[i];
                in1++;
            }
        }
        for(int i=0 ; i<t.size() ; ++i) {
            if(t[i] == '#') {
                if(in2 > 0)
                    in2--;
            }
            else {
                t[in2] = t[i];
                in2++;
            }
        }
        if(in1 != in2) return 0;
        for(int i=0 ; i<in1 ; ++i)
            if(s[i] != t[i])
                return 0;
        return 1;
    }
};
class Solution {
public:
    bool checkOnesSegment(string s) {
        bool t=1;
        for(int i=0 ; i<s.size() ; ++i) {
            if(t==0 and s[i]=='1')
                return 0;
            if(s[i] == '0') 
                t=0;
        }
        return 1;
    }
};
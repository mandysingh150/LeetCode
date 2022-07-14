class Solution {
public:
    string reverseWords(string &s) {
        reverse(begin(s), end(s));
        int si=0;
        while(si<s.size() and s[si]==' ') si++;
        s = s.substr(si);
        for(int i=0 ; i<s.size() ; ) {
            int in=i;
            while(i<s.size() and s[i]!=' ') i++;
            for(int left=in, right=i-1 ; left<right ; ++left, --right) swap(s[left], s[right]);
            if(i<s.size()) {
                in=i;
                while(i<s.size() and s[i]==' ') i++;
                s = s.substr(0, in) + " " + s.substr(i);
                i -= (i-in-1);
            }
        }
        while(!s.empty() and s.back()==' ') s.pop_back();
        return s;
    }
};
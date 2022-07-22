class Solution {
public:
    bool isMatch(string &s, string &p, int in_s=0, int in_p=0) {
        if(in_p >= p.size()) {
            return in_s >= s.size();
        }
        bool ans = (in_s<s.size() and (s[in_s]==p[in_p] or p[in_p]=='.'));
        if(in_p+1<p.size() and p[in_p+1]=='*') {
            return (isMatch(s, p, in_s, in_p+2) or (ans and isMatch(s, p, in_s+1, in_p)));
        }
        return ans and isMatch(s, p, in_s+1, in_p+1);
    }
};
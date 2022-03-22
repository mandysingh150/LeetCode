class Solution {
public:
    int reverse(int x) {
        int sign = x<0 ? -1 : 1;
        string s = to_string(1LL*sign*x);
        std::reverse(begin(s), end(s));
        if(stoll(s)*sign>INT_MAX or stoll(s)*sign<INT_MIN)
            return 0;
        return sign*stoll(s);
    }
};
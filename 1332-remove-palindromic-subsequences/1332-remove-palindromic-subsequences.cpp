class Solution {
public:
    int removePalindromeSub(string &s) {
        bool palindrome = 1;
        for(int i=0, j=s.size()-1 ; i<j ; ++i, --j)
            if(s[i]!=s[j]) {
                palindrome=0;
                break;
            }
        return palindrome ? 1 : 2;
    }
};
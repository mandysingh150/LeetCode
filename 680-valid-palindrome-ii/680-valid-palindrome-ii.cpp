class Solution {
public:
    bool is_palindrome(string &s, int si, int ei) {
        for(int i=si, j=ei ; i<j ; ++i, --j)
            if(s[i]!=s[j])
                return 0;
        return 1;
    }
    bool validPalindrome(string s) {
        for(int i=0, j=s.size()-1 ; i<j ; ++i, --j)
            if(s[i]!=s[j])
                return is_palindrome(s, i, j-1) or is_palindrome(s, i+1, j);
        return 1;
    }
};
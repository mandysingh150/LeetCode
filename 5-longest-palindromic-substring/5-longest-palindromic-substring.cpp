class Solution {
public:
    string longestPalindrome(string s) {
        int si=0, len=1;
        
        // odd length
        for(int i=0 ; i<s.size() ; ++i) {
            int j=i, k=i+2;
            while(j>=0 and k<s.size() and s[j]==s[k])
                --j, ++k;
            if(len < k-j-1)
                len = k-j-1, si=j+1;
        }
            
        // even length
        for(int i=0 ; i<s.size() ; ++i) {
            int j=i, k=i+1;
            while(j>=0 and k<s.size() and s[j]==s[k])
                --j, ++k;
            if(len < k-j-1)
                len = k-j-1, si=j+1;
        }
        return s.substr(si, len);
    }
};
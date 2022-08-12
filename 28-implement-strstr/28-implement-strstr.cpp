class Solution {
public:
    int strStr(string haystack, string needle) {
        // making the LPS array
        vector<int> lps(needle.size(), 0);
        for(int prev_lps=0, i=1 ; i<needle.size() ; ) {
            if(needle[i] == needle[prev_lps]) {
                lps[i] = ++prev_lps;
                i++;
            }
            else if(prev_lps == 0) {
                lps[i] = 0;
                i++;
            }
            else {
                prev_lps = lps[prev_lps - 1];
            }
        }
        
        // KMP algorithm
        int i=0;    // index for haystack
        int j=0;    // index for needle
        for(int i=0, j=0 ; i<haystack.size() ; ) {
            if(haystack[i] == needle[j]) {
                ++i;
                ++j;
            }
            else {
                if(j==0) {
                    i++;
                }
                else {
                    j=lps[j-1];
                }
            }
            if(j == needle.size()) {
                return i-needle.size();
            }
        }
        return -1;
    }
};
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int ans=0;
        for(int i=0, j=s.size()-1 ; i<j ; ) {
            if(s[i] == s[j]) {
                ++i;
                --j;
                continue;
            }
            int k=j-1;
            while(i<k and s[i]!=s[k]) --k;
            if(i == k) {
                swap(s[i], s[i+1]);
                ans++;
            }
            else {
                for(int in=k ; in<j ; ++in)
                    swap(s[in], s[in+1]);
                ans += j-k;
            }
        }
        return ans;
    }
};
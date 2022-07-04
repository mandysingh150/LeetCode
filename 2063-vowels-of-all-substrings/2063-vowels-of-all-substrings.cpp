class Solution {
public:
    long long countVowels(string &s) {
        long long ans=0, n=s.size();
        for(int i=0 ; i<n ; ++i) {
            switch(s[i]) {
                case 'a': case 'e': case 'i': case 'o': case 'u':
                    ans += 1ll*(i+1)*(n-i);
            }
        }
        return ans;
    }
};
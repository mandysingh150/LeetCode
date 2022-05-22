class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        
        // odd length
        for(int i=0 ; i<s.size() ; ++i) {
            int cnt = 1;
            while(i-cnt>=0 and i+cnt<s.size() and s[i-cnt]==s[i+cnt]) cnt++;
            ans += cnt;
        }
        
        // even length
        for(int i=0 ; i<s.size()-1 ; ++i) {
            int cnt=0;
            while(i-cnt>=0 and i+cnt+1<s.size() and s[i-cnt]==s[i+cnt+1]) cnt++;
            ans += cnt;
        }
        
        return ans;
    }
};
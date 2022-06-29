class Solution {
public:
    long long appealSum(string &s) {
        long long ans = 0, n=s.size();
        int prev[26];
        for(int i=0 ; i<26 ; ++i) 
            prev[i]=-1;
        for(int i=0 ; i<n ; ++i) {
            ans += (n-i) * (i-prev[s[i]-'a']);
            prev[s[i]-'a']=i;
        }
        return ans;
    }
};
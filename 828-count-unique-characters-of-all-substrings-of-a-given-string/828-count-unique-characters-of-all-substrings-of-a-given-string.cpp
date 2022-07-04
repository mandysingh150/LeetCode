class Solution {
public:
    int uniqueLetterString(string &s) {
        // vector<vector<int>> a(26, vector<int>{-1});
        vector<int> a[26];
        int n = s.size(), ans=0, cnt[26];
        for(int i=0 ; i<26 ; ++i) {
            a[i].push_back(-1);
            cnt[i]=1;
        }
        for(int i=0 ; i<n ; ++i) {
            a[s[i]-'A'].push_back(i);
        }
        for(int i=0 ; i<26 ; ++i) {
            a[i].push_back(n);
        }
        for(int i=0 ; i<n ; ++i) {
            int x=s[i]-'A', in = cnt[x];
            ans += (a[x][in]-a[x][in-1]) * (a[x][in+1]-a[x][in]);
            cnt[x]++;
        }
        return ans;
    }
};
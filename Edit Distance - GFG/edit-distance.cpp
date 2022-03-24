// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int rec(string &s, int i, string &t, int j, vector<vector<int>> &dp) {
        if(i==s.size())
            return t.size()-j;
        if(j==t.size())
            return s.size()-i;
        if(dp[i][j] != INT_MAX)
            return dp[i][j];
        
        if(s[i]==t[j])
            return rec(s, i+1, t, j+1, dp);
        return dp[i][j] = 1 + min(rec(s, i, t, j+1, dp), min(rec(s, i+1, t, j, dp), rec(s, i+1, t, j+1, dp)));
    }
    
    int editDistance(string& s, string& t) {
        int n1 = s.size(), n2 = t.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, INT_MAX));
        // return rec(s, 0, t, 0, dp);
        
        // DP Approach
        for(int i=0 ; i<=n1 ; ++i)
            dp[i][0] = i;
        for(int i=0 ; i<=n2 ; ++i)
            dp[0][i] = i;
        for(int i=1 ; i<=n1 ; ++i)
            for(int j=1 ; j<=n2 ; ++j) {
                if(i==0)
                    dp[i][j] = j;
                else if(j==0)
                    dp[i][j] = i;
                else
                    dp[i][j] = s[i-1]==t[j-1] ? dp[i-1][j-1] : 1+min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        return dp[n1][n2];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int dp[21][21][21];
int h(string &a, int in_a, string &b, int in_b, string &c, int in_c) {
    if(in_a==a.size() or in_b==b.size() or in_c==c.size()) {
        return 0;
    }
    if(dp[in_a][in_b][in_c] != -1) {
        return dp[in_a][in_b][in_c];
    }
    if(a[in_a]==b[in_b] and b[in_b]==c[in_c]) {
        return dp[in_a][in_b][in_c] = 1 + h(a, in_a+1, b, in_b+1, c, in_c+1);
    }
    return dp[in_a][in_b][in_c] = max(h(a, in_a+1, b, in_b, c, in_c), max(h(a, in_a, b, in_b+1, c, in_c), h(a, in_a, b, in_b, c, in_c+1)));
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    memset(dp, -1, sizeof(dp));
    return h(A, 0, B, 0, C, 0);
}
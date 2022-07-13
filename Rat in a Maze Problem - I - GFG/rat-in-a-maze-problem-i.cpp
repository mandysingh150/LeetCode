// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++
int dir[]={-1,0,1,0,-1};
string path="URDL";
class Solution{
    public:
    int vis[5][5];
    vector<string> ans;
    void h(vector<vector<int>> &a, int n, int row, int col, string &t) {
        if(row==n-1 and col==n-1) {
            ans.push_back(t);
            return;
        }
        vis[row][col] = 1;
        for(int i=0 ; i<4 ; ++i) {
            int x=row+dir[i], y=col+dir[i+1];
            if(x>=0 and x<n and y>=0 and y<n and a[x][y] and !vis[x][y]) {
                t.push_back(path[i]);
                h(a, n, x, y, t);
                t.pop_back();
            }
        }
        vis[row][col] = 0;
    }
    vector<string> findPath(vector<vector<int>> &a, int n) {
        memset(vis, 0, sizeof(vis));
        if(a[0][0] == 1) {
            string t="";
            h(a, n, 0, 0, t);
        }
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
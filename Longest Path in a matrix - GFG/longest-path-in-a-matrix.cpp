// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

int dir[] = {-1,0,1,0,-1};
class Solution {
public:
    int n,m,ans;
    bool is_safe(int i, int j) {
        return i>=0 and i<n and j>=0 and j<m;
    }
    int dfs(vector<vector<int>> &a, int row, int col, vector<vector<int>> &vis) {
        if(vis[row][col] != -1)
            return vis[row][col];
        int val=1;
        for(int k=0 ; k<4 ; ++k) {
            int x=dir[k]+row, y=dir[k+1]+col;
            if(is_safe(x, y) and a[x][y]>a[row][col])
                val = max(val, 1+dfs(a, x, y, vis));
        }
        return vis[row][col] = val;
    }
    int longestIncreasingPath(vector<vector<int>>& a) {
        n=a.size(), m=a[0].size(), ans=0;
        vector<vector<int>> vis(n, vector<int>(m, -1));
        for(int i=0 ; i<n ; ++i) {
            for(int j=0 ; j<m ; ++j) {
                int val=0;
                if(vis[i][j]==-1)
                    val = dfs(a, i, j, vis);
                ans = max(val, ans);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
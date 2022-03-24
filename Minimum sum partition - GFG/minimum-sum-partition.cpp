// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i=0 ; i<n ; ++i) {
	        sum += arr[i];
	    }
	    bool dp[n+1][sum+1];
	    for(int i=0 ; i<n+1 ; ++i) {
	        for(int j=0 ; j<=sum/2 ; ++j) {
	            if(i==0 or j==0) {
	                if(i==0) dp[i][j] = 0;
                    if(j==0) dp[i][j] = 1;
	            }
	            else {
	                if(arr[i-1] <= j) 
	                    dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
	                else
	                    dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    int ans = INT_MAX;
	    for(int i=0 ; i<=sum/2 ; ++i) {
	        if(dp[n][i])
	            ans = min(ans, sum-2*i);
	    }
	    return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
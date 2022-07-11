// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int at[], int dt[], int n)
    {
    	vector<pair<int,int>> v(2*n);
        for(int i=0 ; i<n ; i++) {
            v[2*i] = {at[i], 0};
            v[2*i+1] = {dt[i]+1, 1};
        }
        sort(v.begin(), v.end());
        int cnt=0, mx=0;
        for(int i=0 ; i<v.size() ; ) {
            int val=v[i].first, temp=v[i].second;
            i++;
            while(i<v.size() and v[i].first==val) {
                cnt += (v[i].second ? -1 : 1);
                i++;            
            }
            cnt += (temp ? -1 : 1);
            mx = max(mx, cnt);
        }
        return mx;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends
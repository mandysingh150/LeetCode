// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool check(int a[], int n, int m, int mid) {
        int cnt=0, sum=0, mx=0;
        for(int i=0 ; i<n ; ++i) {
            if(a[i] > mid)
                return 0;
            if(sum + a[i] > mid) {
                cnt++;
                sum = a[i];
            }
            else
                sum += a[i];
        }
        return cnt<m;
    }
    int findPages(int A[], int N, int M) 
    {
        long long l=0, h=0, ans=INT_MAX;
        for(int i=0 ; i<N ; ++i) {
            h+=A[i];
        }
        while(l<=h) {
            long long mid = (l+h)>>1;
            if(check(A, N, M, mid)) {
                ans = mid;
                h=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends
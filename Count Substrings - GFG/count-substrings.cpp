// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int countSubstr (string s)
	{
	   int cnt1=0, ans=0;
	    for(int i=0 ; i<s.size() ; ++i)  {
	        if(s[i]=='1') {
	            ans += cnt1;
	            cnt1++;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        
        cout << ob.countSubstr (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends
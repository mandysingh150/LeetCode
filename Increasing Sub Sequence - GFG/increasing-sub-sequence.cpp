// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int maxLength(string &s) {
        vector<char> v;
        v.push_back(s[0]);
        for(int i=0 ; i<s.size() ; ++i) {
            auto in = lower_bound(v.begin(), v.end(), s[i]) - v.begin();
            if(in == v.size()) {
                v.push_back(s[i]);
            }
            else {
                v[in] = s[i];
            }
        }
        return v.size();
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout << ob.maxLength(S) << endl;
    }
    return 0; 
}  // } Driver Code Ends
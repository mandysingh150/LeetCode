// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> v;
    void h(vector<int> &a, int in, int sum) {
        if(in == a.size()) {
            v.push_back(sum);
            return;
        }
        h(a, in+1, sum);
        h(a, in+1, sum+a[in]);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        h(arr, 0, 0);
        return v;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
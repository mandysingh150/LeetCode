// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& a) {
         sort(begin(a), end(a), [](vector<int> &c, vector<int> &d) {
             return c[0]<d[0];
         });
         int si=a[0][0], ei=a[0][1];
         vector<vector<int>> v;
         for(int i=1 ; i<=a.size() ; ++i) {
             if(i==a.size()) {
                 v.push_back({si, ei});
                 break;
             }
             if(a[i][0]<=ei) {
                 si = min(si, a[i][0]);
                 ei = max(ei, a[i][1]);
             }
             else {
                 v.push_back({si, ei});
                 si=a[i][0];
                 ei=a[i][1];
             }
         }
         return v;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends
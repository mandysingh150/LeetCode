// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int s[], int f[], int n)
    {
        vector<pair<int,int>> v;
        for(int i=0 ; i<n ; ++i) {
            v.push_back({s[i], f[i]});
        }
        sort(begin(v), end(v), [](pair<int,int> &c, pair<int,int> &d) {
            return c.second < d.second;
        });
        int cnt=0, prev_end=-1;
        for(int i=0 ; i<n ; ++i) {
            if(prev_end < v[i].first) {
                cnt++;
                prev_end=v[i].second;
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
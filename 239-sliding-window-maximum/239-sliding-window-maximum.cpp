class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        // int ans=0, mx=INT_MIN;
        multiset<int, greater<int>> s;
        vector<int> v;
        for(int i=0 ; i<a.size(); ++i) {
            if(i>=k) {
                // ans -= a[i-k];
                s.erase(s.find(a[i-k]));
            }
            // ans += a[i];
            s.insert(a[i]);
            // mx = max(mx, ans);
            if(i>=k-1)
                v.push_back(*s.begin());
        }
        return v;
    }
};
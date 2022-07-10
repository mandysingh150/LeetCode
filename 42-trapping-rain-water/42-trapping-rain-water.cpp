class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size();
        vector<int> lr(n), rl(n);
        lr[0]=a[0];
        rl[n-1]=a[n-1];
        for(int i=1 ; i<n ; ++i) {
            lr[i] = max(lr[i-1], a[i]);
        }
        for(int i=n-2 ; i>=0 ; --i) {
            rl[i] = max(rl[i+1], a[i]);
        }
        int ans=0;
        for(int i=0 ; i<n ; ++i) {
            ans += min(lr[i], rl[i]) - a[i];
        }
        return ans;
    }
};
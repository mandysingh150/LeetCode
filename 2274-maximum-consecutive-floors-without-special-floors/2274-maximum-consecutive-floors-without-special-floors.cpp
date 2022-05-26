class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& a) {
        int prev = bottom-1, ans=0;
        sort(begin(a), end(a));
        a.push_back(top+1);
        for(int i=0 ; i<a.size() ; ++i) {
            ans = max(ans, a[i]-prev-1);
            prev=a[i];
        }
        return ans;
    }
};
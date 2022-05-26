class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& a) {
        int ans=0;
        a.push_back(top+1);
        a.push_back(bottom-1);
        sort(begin(a), end(a));
        for(int i=1 ; i<a.size() ; ++i)
            ans = max(ans, a[i]-a[i-1]-1);
        return ans;
    }
};
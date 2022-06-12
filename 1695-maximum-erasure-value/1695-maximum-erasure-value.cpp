class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) {
        int si=0, ei=0, sum=0, mx=0;
        unordered_set<int> s;
        while(ei<a.size()) {
            while(s.count(a[ei])) {
                s.erase(a[si]);
                sum -= a[si];
                si++;
            }
            s.insert(a[ei]);
            sum += a[ei];
            ei++;
            mx = max(mx, sum);
        }
        return mx;
    }
};
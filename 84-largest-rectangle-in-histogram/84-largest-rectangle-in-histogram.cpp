class Solution {
public:
    vector<int> left_sm(vector<int> &a) {
        stack<int> s;
        vector<int> v;
        for(int i=0; i<a.size(); ++i) {
            while(!s.empty() and a[s.top()]>=a[i]) s.pop();
            v.push_back((s.empty() ? -1 : s.top()));
            s.push(i);
        }
        return v;
    }
    vector<int> right_sm(vector<int> &a) {
        stack<int> s;
        vector<int> v;
        for(int i=a.size()-1; i>=0; --i) {
            while(!s.empty() and a[s.top()]>=a[i]) s.pop();
            v.push_back((s.empty() ? a.size() : s.top()));
            s.push(i);
        }
        reverse(begin(v), end(v));
        return v;
    }
    int largestRectangleArea(vector<int>& a) {
        auto left = left_sm(a), right = right_sm(a);
        long long ans=0;
        for(int i=0 ; i<a.size(); ++i) {
            ans = max(ans, 1ll*a[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& a) {
        stack<int> s;
        vector<int> next_gr(a.size());
        for(int i=a.size()-1 ; i>=0 ; --i) {
            while(!s.empty() and s.top() <= a[i]) {
                s.pop();
            }
            next_gr[i] = s.empty() ? -1 : s.top();
            s.push(a[i]);
        }
        vector<int> v;
        for(auto i: nums1) {
            for(int j=0 ; j<a.size() ; ++j) {
                if(a[j] == i) {
                    v.push_back(next_gr[j]);
                }
            }
        }
        return v;
    }
};
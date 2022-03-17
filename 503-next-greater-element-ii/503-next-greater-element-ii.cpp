class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        stack<int> s;
        // {max_value, index}
        pair<int,int> mx={INT_MIN, -1};
        vector<int> v(a.size());
        for(int i=a.size()-1 ; i>=0 ; --i) {
            while(!s.empty() and s.top()<=a[i])
                s.pop();
            v[i] = s.empty() ? -1 : s.top();
            s.push(a[i]);
            if(mx.first < a[i])
                mx = {a[i], i};                
        }
        while(!s.empty())
            s.pop();
        s.push(mx.first);
        for(int i=(mx.second+a.size()-1)%a.size() ; i!=mx.second ; i=(a.size()+i-1)%a.size()) {
            while(!s.empty() and s.top()<=a[i])
                s.pop();
            if(!s.empty())
                v[i] = s.top();
            s.push(a[i]);
        }
        return v;
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int i=0;
        vector<int> v;
        while(i<a.size() and a[i]<0) {
            v.push_back(a[i]);
            i++;
        }
        stack<int> s;
        while(i<a.size()) {
            if(a[i] > 0) {
                s.push(a[i]);
            }
            else {
                while(!s.empty() and s.top()<-a[i]) {
                    s.pop();
                }
                if(s.empty()) {
                    v.push_back(a[i]);
                }
                else if(s.top() == -a[i]) {
                    s.pop();
                }
            }
            i++;
        }
        vector<int> t;
        while(!s.empty()) {
            t.push_back(s.top());
            s.pop();
        }
        for(int i=t.size()-1 ; i>=0 ; --i) {
            v.push_back(t[i]);
        }
        return v;
    }
};
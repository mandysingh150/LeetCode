class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(auto i: ops) {
            if(i[0] == 'C') {
                s.pop();
            }
            else if(i[0] == 'D') {
                s.push(s.top()*2);
            }
            else if(i[0] == '+') {
                auto t1=s.top(); s.pop();
                int t = t1+s.top();
                s.push(t1);
                s.push(t);                
            }
            else {
                s.push(stoi(i));
            }
        }
        int val=0;
        while(!s.empty()) {
            val += s.top(); 
            s.pop();
        }
        return val;
    }
};
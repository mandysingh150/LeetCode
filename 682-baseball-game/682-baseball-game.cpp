class Solution {
public:
    int calPoints(vector<string>& ops) {
        int s[1001], in=-1;
        for(auto i: ops) {
            if(i[0] == 'C') {
                in--;
            }
            else if(i[0] == 'D') {
                in++;
                s[in] = s[in-1]*2;
            }
            else if(i[0] == '+') {
                in++;
                s[in] = s[in-1] + s[in-2];
            }
            else {
                in++;
                s[in] = stoi(i);
            }
        }
        int val=0;
        for(int i=0 ; i<=in ; ++i) {
            val += s[i];
        }
        return val;
    }
};
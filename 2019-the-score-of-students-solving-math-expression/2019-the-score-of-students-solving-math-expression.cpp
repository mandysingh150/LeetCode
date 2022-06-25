class Solution {
public:
    unordered_set<int> dp[32][32];
    void h(vector<int> &exp, int si, int ei) {
        if(dp[si][ei].empty()) {
            if(si == ei) {
                dp[si][ei].insert(exp[si]);
                return;
            }
            for(int i=si+1 ; i<ei ; i+=2) {
                h(exp, si, i-1);
                h(exp, i+1, ei);
                for(auto l_ans: dp[si][i-1]) {
                    for(auto r_ans: dp[i+1][ei]) {
                        int val = exp[i] == -1111 ? l_ans + r_ans : l_ans * r_ans;
                        if(val <= 1000)
                            dp[si][ei].insert(val);
                    }
                }
            }
        }
    }
    int scoreOfStudents(string &s, vector<int>& answers) {
        vector<int> exp;
        for(auto i: s) {
            exp.push_back((i=='+' ? -1111 : (i=='*' ? 1111 : i-'0')));
        }
        
        // getting the correct answer
        vector<int> v{exp[0]};
        for(int i=1 ; i<exp.size() ; i+=2) {
            if(exp[i] == -1111)
                v.push_back(exp[i+1]);
            else
                v[v.size()-1] *= exp[i+1];
        }
        int correct_answer = accumulate(begin(v), end(v), 0ll);
        
        h(exp, 0, exp.size()-1);
        
        int val=0;
        for(auto i: answers) {
            if(i == correct_answer)
                val += 5;
            else if(dp[0][exp.size()-1].count(i))
                val += 2;
        }
        return val;
    }
};
class Solution {
public:
    unordered_set<int> dp[32][32];
    void h(string &s, int si, int ei) {
        if(dp[si][ei].empty()) {
            if(si == ei)
                dp[si][ei].insert(s[si]-'0');
            for(int i=si+1 ; i<ei ; i+=2) {
                h(s, si, i-1);
                h(s, i+1, ei);
                for(auto l_ans: dp[si][i-1]) {
                    for(auto r_ans: dp[i+1][ei]) {
                        int val = (s[i] == '+' ? l_ans+r_ans : l_ans*r_ans);
                        if(val <= 1000)
                            dp[si][ei].insert(val);
                    }
                }
            }
        }
    }
    int scoreOfStudents(string &s, vector<int>& answers) {
        // getting the correct answer
        vector<int> v{s[0]-'0'};
        for(int i=1 ; i<s.size() ; i+=2) {
            if(s[i] == '+')
                v.push_back(s[i+1]-'0');
            else
                v[v.size()-1] *= (s[i+1]-'0');
        }
        int correct_answer = accumulate(begin(v), end(v), 0ll);
        
        h(s, 0, s.size()-1);
        
        int val=0;
        for(auto i: answers) {
            if(i == correct_answer)
                val += 5;
            else if(dp[0][s.size()-1].count(i))
                val += 2;
        }
        return val;
    }
};
class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0, layers=0;
        for(int i=0 ; i<s.size() ; ++i) {
            if(s[i] == '(') layers++;
            else layers--;
            if(s[i]==')' and s[i-1]=='(')
                ans += 1<<layers;
        }
        return ans;
    }
};
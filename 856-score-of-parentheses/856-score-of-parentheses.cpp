class Solution {
public:
    int get_score(string &s, vector<int> &ei, int in) {
        if(in > s.size())
            return 0;
        if(ei[in] == in+1)
            return 1;
        
        int val=0;
        for(int i=in+1 ; i<ei[in] ; ++i) {
            val += get_score(s, ei, i);
            i=ei[i];
        }
        return val<<1;
    }
    int scoreOfParentheses(string s) {
        vector<int> ei(s.size(), -1);
        stack<int> st;
        for(int i=0 ; i<s.size() ; ++i) {
            if(s[i]=='(') 
                st.push(i);
            else {
                ei[st.top()] = i;
                st.pop();
            }
        }
        if(ei[0] != s.size()-1) {
            string t = "(" + s + ")";
            vector<int> temp(t.size(), -1);
            temp[0]=t.size()-1;
            for(int i=1 ; i<t.size()-1 ; ++i)
                temp[i] = ei[i-1]==-1 ? ei[i-1] : ei[i-1]+1;
            return get_score(t, temp, 0)>>1;
        }
        return get_score(s, ei, 0);
    }
};
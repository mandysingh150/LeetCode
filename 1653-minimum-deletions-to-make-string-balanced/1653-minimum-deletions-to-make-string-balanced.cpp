class Solution {
public:
    int minimumDeletions(string s) {
        stack<int> st;
        int cnt=0;
        for(int i=0 ; i<s.size() ; ++i) {
            if(!st.empty() and st.top()=='b' and s[i]=='a')
                st.pop(), ++cnt;
            else
                st.push(s[i]);
        }
        return cnt;
    }
};
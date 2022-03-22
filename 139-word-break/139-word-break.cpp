class Solution {
public:
    unordered_set<string> st;
    bool h(string &s, int in) {
        // sotre the starting_index of the string which may be present in "st"
        queue<int> q;
        unordered_set<int> vis;
        q.push(0);
        vis.insert(0);
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            
            string t;
            for(int i=top ; i<s.size() ; ++i) {
                t += s[i];
                if(st.count(t) and vis.count(i+1)==0) {
                    q.push(i+1);
                    vis.insert(i+1);
                    if(i+1 == s.size())
                        return 1;
                }
            }
        }
        return 0;
        // if(in==s.size())
        //     return 1;
        // string t;
        // for(int i=in ; i<s.size() ; ++i) {
        //     t += s[i];
        //     if(st.count(t) and h(s, i+1))
        //         return 1;
        // }
        // return 0;
    }
    bool wordBreak(string &s, vector<string>& wordDict) {
        st.clear();
        for(auto i: wordDict) 
            st.insert(i);
        return h(s, 0);
    }
};
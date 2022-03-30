class Solution {
public:
    unordered_set<string> st;
    bool wordBreak(string &s, vector<string>& wordDict) {
        st.clear();
        for(auto i: wordDict)
            st.insert(i);
        
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
                    if(i+1 == s.size())
                        return 1;
                    q.push(i+1);
                    vis.insert(i+1);
                }
            }
        }
        return 0;
    }
};
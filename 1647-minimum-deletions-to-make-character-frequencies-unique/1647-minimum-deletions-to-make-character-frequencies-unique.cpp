class Solution {
public:
    int minDeletions(string &s) {
        int mp[26]={0};
        for(auto i: s) {
            mp[i-'a']++;
        }
        unordered_set<int> st;
        int ans=0;
        for(int i=0 ; i<26 ; ++i) {
            int cnt=mp[i];
            if(cnt>0) {
                if(st.count(cnt)) {
                    while(st.count(cnt))
                        cnt--, ans++;
                    if(cnt>0)
                        st.insert(cnt);
                }
                else {
                    st.insert(cnt);
                }
            }
        }
        return ans;
    }
};
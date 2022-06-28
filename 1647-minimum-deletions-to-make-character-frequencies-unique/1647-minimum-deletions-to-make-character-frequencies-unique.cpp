class Solution {
public:
    int minDeletions(string &s) {
        unordered_map<int,int> mp;
        for(auto i: s) {
            mp[i]++;
        }
        unordered_set<int> st;
        int ans=0;
        for(auto [ch,cnt]: mp) {
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
        return ans;
    }
};
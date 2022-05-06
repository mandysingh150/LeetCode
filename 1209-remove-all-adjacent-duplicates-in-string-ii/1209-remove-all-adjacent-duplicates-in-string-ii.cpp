class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int,int>> st;
        for(int i=0 ; i<s.size() ; ) {
            int cnt=1, ch=s[i];
            i++;
            while(i<s.size() and s[i]==ch) {
                ++cnt;
                ++i;
            }
            if(!st.empty() and st.top().first == ch) {
                cnt += st.top().second;
                st.pop();
            }
            cnt %= k;
            if(cnt > 0)
                st.push({ch, cnt});
        }
        string ans;
        while(!st.empty()) {
            ans += string(st.top().second, st.top().first);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
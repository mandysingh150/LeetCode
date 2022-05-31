class Solution {
public:
    bool hasAllCodes(string &s, int k) {
        unordered_set<int> st;
        int val=0;
        for(int i=0 ; i<s.size() ; ++i) {
            val <<= 1;
            if(i>=k)
                val &= (~(1<<k));
            val += (s[i]=='1');
            if(i>=k-1)
                st.insert(val);
        }
        return st.size()==(1<<k);
    }
};
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while(n > 1) {
            string s = to_string(n);
            int sum=0;
            for(auto &i: s) {
                sum += (i-'0')*(i-'0');
            }
            if(st.count(sum))
                break;
            st.insert(sum);
            n = sum;            
        }
        return n==1;
    }
};
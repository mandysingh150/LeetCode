class Solution {
public:
    int gcd(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    vector<int> replaceNonCoprimes(vector<int>& a) {
        stack<int> st;
        st.push(a[0]);
        for(int i=1 ; i<a.size() ; ++i) {
            st.push(a[i]);
            while(st.size()>=2) {
                int n1=st.top(); st.pop();
                int n2=st.top(); st.pop();
                int my_gcd=gcd(n1, n2);
                if(my_gcd > 1)
                    st.push(1ll*n1*n2/my_gcd);
                else {
                    st.push(n2);
                    st.push(n1);
                    break;
                }
            }
        }
        a.clear();
        while(!st.empty()) {
            a.push_back(st.top());
            st.pop();
        }
        reverse(begin(a), end(a));
        return a;
    }
};
class Solution {
public:
    vector<int> v;
    void help(string &s, int n, int k) {
        if(n==0) {
            v.push_back(stoi(s));
            return;
        }
        char ch=s.back();
        vector<int> t={1};
        if(k>0) t.push_back(-1);
        for(auto i: t)
            if(ch+i*k>='0' and ch+i*k<='9') {
                s.push_back(ch+i*k);
                help(s, n-1, k);
                s.pop_back();
            }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string s="";
        for(int i=1 ; i<=9 ; ++i) {
            s.push_back('0'+i);
            help(s, n-1, k);
            s.pop_back();
        }
        return v;
    }
};
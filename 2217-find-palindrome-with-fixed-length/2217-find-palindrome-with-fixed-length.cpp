class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& a, int n) {
        vector<long long> v;
        long long start=pow(10, (n-1)>>1), end=pow(10, (n+1)>>1);
        for(auto i: a) {
            if(start+i-1 >= end)
                v.push_back(-1);
            else {
                string s = to_string(start+i-1);
                string t = s;
                t.resize(n/2);
                reverse(t.begin(), t.end());
                s += t;
                v.push_back(stoll(s));
            }
        }
        return v;
    }
};
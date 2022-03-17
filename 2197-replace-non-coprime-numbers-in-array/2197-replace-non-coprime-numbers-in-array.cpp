class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& a) {
        vector<int> v;
        for(int i=0 ; i<a.size() ; ++i) {
            v.emplace_back(a[i]);
            while(v.size()>1 and __gcd(v.back(), v[v.size()-2])>1) {
                long long a=v.back(), b=v[v.size()-2], gcd=__gcd(a,b);
                v.pop_back();
                v.pop_back();
                v.push_back(a*b/gcd);
            }
        }
        return v;
    }
};
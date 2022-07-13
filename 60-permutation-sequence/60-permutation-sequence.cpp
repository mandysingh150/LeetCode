class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> v;
        for(int i=1 ; i<n ; ++i) {
            fact *= i;
            v.push_back(i);
        }
        v.push_back(n);
        --k;
        string s="";
        while(1) {
            s.push_back('0'+v[k/fact]);
            v.erase(v.begin()+k/fact);
            if(v.empty()) {
                break;
            }
            k %= fact;
            fact /= v.size();
        }
        return s;
    }
};
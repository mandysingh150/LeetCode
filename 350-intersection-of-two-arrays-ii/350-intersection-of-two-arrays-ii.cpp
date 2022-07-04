class Solution {
public:
    vector<int> intersect(vector<int>& n1, vector<int>& n2) {
        unordered_map<int,int> mp1, mp2;
        vector<int> v;
        for(auto i: n1) mp1[i]++;
        for(auto i: n2) mp2[i]++;
        for(auto [a,b]: mp1) {
            if(mp2.count(a)) {
                int val=min(b, mp2[a]);
                while(val--) {
                    v.push_back(a);
                }
            }
        }
        return v;
    }
};
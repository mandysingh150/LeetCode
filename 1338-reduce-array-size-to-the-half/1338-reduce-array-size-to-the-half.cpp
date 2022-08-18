class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> mp;
        for(auto i: arr) mp[i]++;
        vector<int> v;
        int sum=0;
        for(auto [a,b]: mp) v.push_back(b);
        sort(begin(v), end(v), greater<int>());
        for(int i=0 ; i<v.size() ; i++) {
            sum += v[i];
            if(sum >= arr.size()/2) {
                return i+1;
            }
        }
        return v.size();
    }
};
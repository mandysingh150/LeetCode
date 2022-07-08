class Solution {
public:
    vector<int> twoSum(vector<int>& a, int x) {
        vector<pair<int,int>> v;
        for(int i=0 ; i<a.size() ; ++i) {
            v.push_back({a[i], i});
        }
        sort(begin(v), end(v));
        int i=0, j=a.size()-1;
        while(i<j) {
            int sum = v[i].first + v[j].first;
            if(sum == x) {
                return {v[i].second, v[j].second};
            }
            else if(sum < x) {
                i++;
            }
            else {
                j--;
            }
        }
        return {};
    }
};
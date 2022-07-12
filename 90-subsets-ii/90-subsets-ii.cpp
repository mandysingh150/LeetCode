class Solution {
public:
    vector<vector<int>> s;
    void h(vector<int> &a, int in, vector<int> &v) {
        s.push_back(v);
        for(int i=in ; i!=a.size() ; ++i) {
            if(i==in || a[i] != a[i-1]) {
                v.push_back(a[i]);
                h(a, i+1, v);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        h(nums, 0, v);
        return s;
    }
};
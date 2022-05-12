class Solution {
public:
    void h(vector<int> &a, int in, set<vector<int>> &s) {
        if(in == a.size()) {
            s.insert(a);
            return;
        }
        for(int i=in ; i<a.size() ; ++i) {
            swap(a[in], a[i]);
            h(a, in+1, s);
            swap(a[in], a[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        h(nums, 0, s);
        return vector<vector<int>>(s.begin(), s.end());
    }
};
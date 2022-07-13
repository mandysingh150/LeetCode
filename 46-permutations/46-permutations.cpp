class Solution {
public:
    vector<vector<int>> ans;
    void h(vector<int> &a, int in) {
        if(in == a.size()) {
            ans.push_back(a);
        }
        for(int i=in ; i<a.size() ; ++i) {
            swap(a[i], a[in]);
            h(a, in+1);
            swap(a[i], a[in]);
        }
    }
    vector<vector<int>> permute(vector<int>& a) {
        h(a, 0);
        return ans;
    }
};
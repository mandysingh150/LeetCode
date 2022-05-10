class Solution {
public:
    vector<vector<int>> a;
    void h(int i, vector<int> &v, int sum, int k) {
        if(i==10 or sum<=0 or v.size()>=k) {
            if(sum == 0 and v.size()==k)
                a.push_back(v);
            return;
        }
        h(i+1, v, sum, k);
        v.push_back(i);
        h(i+1, v, sum-i, k);
        v.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        a.clear();
        h(1, v, n, k);
        return a;
    }
};
class Solution {
public:
    vector<vector<int>> permute(vector<int>& a) {
        vector<vector<int>> v;
        sort(begin(a), end(a));
        do {
            v.push_back(a);
        } while(next_permutation(begin(a), end(a)));
        return v;
    }
};
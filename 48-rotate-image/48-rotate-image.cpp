class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        for(int i=0 ; i<a.size() ; ++i) {
            for(int j=0 ; j<i ; ++j) {
                swap(a[i][j], a[j][i]);
            }
        }
        for(int i=0 ; i<a.size() ; ++i) {
            for(int j=0 ; j<a[0].size()/2 ; ++j) {
                swap(a[i][j], a[i][a[0].size()-1-j]);
            }
        }
    }
};
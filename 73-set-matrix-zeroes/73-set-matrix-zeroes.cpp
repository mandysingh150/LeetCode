class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        bool row_0=0;
        for(int i=0 ; i<a.size() ; ++i) {
            for(int j=0 ; j<a[0].size() ; ++j) {
                if(a[i][j] == 0) {
                    if(i == 0) row_0=1;
                    else a[i][0] = 0;
                    a[0][j] = 0;
                }
            }
        }
        for(int i=1 ; i<a.size() ; ++i) {
            if(a[i][0] == 0) {
                for(int j=1 ; j<a[0].size() ; ++j) {
                    a[i][j]=0;
                }
            }
        }
        for(int j=0 ; j<a[0].size() ; ++j) {
            if(a[0][j] == 0) {
                for(int i=1 ; i<a.size() ; ++i) {
                    a[i][j]=0;
                }
            }
        }
        if(row_0) {
            for(int j=0 ; j<a[0].size() ; ++j) {
                a[0][j]=0;
            }
        }
    }
};
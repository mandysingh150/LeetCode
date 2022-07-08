class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int x) {
        int m=a.size(), n=a[0].size();
        for(int i=m-1, j=0 ; i>=0 and j<n ; ) {
            if(a[i][j] == x) return 1;
            else if(a[i][j] < x) ++j;
            else --i;
        }
        return 0;
    }
};
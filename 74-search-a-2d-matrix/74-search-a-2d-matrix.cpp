class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int m=a.size(), n=a[0].size();
        for(int i=0, j=n-1 ; i<m and j>=0 ; ) {
            if(a[i][j] == target)
                return 1;
            else if(a[i][j] < target)
                ++i;
            else
                --j;
        }
        return 0;
    }
};
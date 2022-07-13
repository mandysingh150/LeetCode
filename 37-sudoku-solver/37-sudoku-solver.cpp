class Solution {
public:
    unordered_set<int> box[3][3], r[9], c[9];
    
    bool helper(vector<vector<char>>& a, int row, int col) {
        if(row == 9)
            return 1;
        if(col == 9)
            return helper(a, row+1, 0);
        if(a[row][col] != '.')
            return helper(a, row, col+1);
        else
            for(int i=1 ; i<=9 ; ++i)
                if(r[row].count(i)==0 && c[col].count(i)==0 && box[row/3][col/3].count(i)==0) {
                    a[row][col] = '0'+i;
                    r[row].insert(i);
                    c[col].insert(i);
                    box[row/3][col/3].insert(i);
                    
                    if(helper(a, row, col+1))
                        return 1;

                    a[row][col] = '.';
                    r[row].erase(i);
                    c[col].erase(i);
                    box[row/3][col/3].erase(i);
                }
        return 0;
    }
    
    void solveSudoku(vector<vector<char>>& a) {
        // storing the elements of in corresponding unordered_set
        for(int i=0 ; i<9 ; ++i)
            for(int j=0 ; j<9 ; ++j)
                if(a[i][j] != '.') {
                    r[i].insert(a[i][j]-'0');
                    c[j].insert(a[i][j]-'0');
                    box[i/3][j/3].insert(a[i][j]-'0');
                }
        helper(a, 0, 0);
    }
};
class Solution {
public:
    bool same(vector<char>& a, int si, int ei, string &s) {
        if(ei-si+1 != s.size())
            return 0;
        int i;
        for(i=0 ; i<s.size() and (a[si+i]==' ' or a[si+i]==s[i]) ; ++i);
        if(i==s.size())
            return 1;
        for(i=0 ; i<s.size() and (a[ei-i]==' ' or a[ei-i]==s[i]) ; ++i);
        return i==s.size();
    }
    bool match(vector<vector<char>>& a, string &s) {
        for(auto &row: a) {
            for(int i=0 ; i<a[0].size() ; ++i) {
                while(i<a[0].size() and row[i]=='#') {
                    ++i;
                }
                int si=i;
                while(i<a[0].size() and row[i]!='#') {
                    ++i;
                }
                if(same(row, si, i-1, s))
                    return 1;
            }
        }
        return 0;
    }
    bool placeWordInCrossword(vector<vector<char>>& A, string &s) {
        // Let 'B' be the transpose of 'A'.
        // we can scan the string directly from left to right horizontally
        // for scanning right to left, we search for the reversed string in the matrix
        // for top to bottom and bottom to top checking, we will use the transposed matrix
        
        int m=A.size(), n=A[0].size();
        vector<vector<char>> B(n, vector<char>(m));
        for(int i=0 ; i<m ; ++i) {
            for(int j=0 ; j<n; ++j) {
                B[j][i] = A[i][j];
            }
        }
        return match(A, s) or match(B, s);
    }
};
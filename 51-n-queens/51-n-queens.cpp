class Solution {
public:
    vector<vector<string>> v;
    void h(int n, int i, vector<string> &a) {
        if(i == n) {
            v.push_back(a);
            return;
        }
        for(int in=0 ; in<n ; ++in) {
            bool queen_present=0;
            for(int off=1 ; off<=i ; ++off) {
                if(a[i-off][in]=='Q' or (in+off<n and a[i-off][in+off]=='Q') or (in-off>=0 and a[i-off][in-off]=='Q')) {
                    queen_present=1;
                    break;
                }
            }
            if(!queen_present) {
                a[i][in] = 'Q';
                h(n, i+1, a);
                a[i][in] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        v.clear();
        vector<string> a(n, string(n, '.'));
        h(n, 0, a);
        return v;
    }
};
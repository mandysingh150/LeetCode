class Solution {
public:
    int cnt;
    vector<vector<int>> v;
    void h(int n, int i) {
        if(i == n) {
            ++cnt;
            return;
        }
        for(int col=0 ; col<n ; ++col) {
            bool queen_present = 0;
            for(int off=1 ; off<=i ; ++off) {
                if(v[i-off][col] or (col-off>=0 and v[i-off][col-off]) or (col+off<n and v[i-off][col+off])) {
                    queen_present=1;
                    break;
                }
            }
            if(!queen_present) {
                v[i][col] = 1;
                h(n, i+1);
                v[i][col] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        cnt = 0;
        v = vector<vector<int>>(n, vector<int>(n, 0));
        h(n, 0);
        return cnt;
    }
};
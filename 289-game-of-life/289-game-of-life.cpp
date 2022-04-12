int dir[][2] = {{-1,-1}, {-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> a = board;
        for(int i=0 ; i<a.size() ; ++i) {
            for(int j=0 ; j<a[0].size() ; ++j) {
                int cnt_alive=0;
                for(int k=0 ; k<8 ; ++k) {
                    int x = dir[k][0]+i, y=dir[k][1]+j;
                    if(x>=0 and y>=0 and x<a.size() and y<a[0].size() and a[x][y])
                        cnt_alive++;
                }
                if(a[i][j]) {   // alive
                    if(cnt_alive < 2)
                        board[i][j]=0;
                    else if(cnt_alive <= 3)
                        board[i][j]=1;
                    else
                        board[i][j]=0;
                }
                else {
                    if(cnt_alive == 3)
                        board[i][j]=1;
                }
            }
        }
    }
};
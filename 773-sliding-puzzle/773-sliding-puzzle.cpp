int dir[]={-1,0,1,0,-1};
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& a) {
        queue<string> q;
        string val = "";
        for(int i=0 ; i<2 ; ++i) {
            for(int j=0 ; j<3 ; ++j) {
                val.push_back(a[i][j]+'0');
            }
        }
        // cout<<val<<"\n";
        q.push(val);
        unordered_set<string> s;
        s.insert(val);
        int len=0;
        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                auto top = q.front();
                q.pop();
                
                if(top.compare("123450") == 0)
                    return len;
                
                for(int i=0 ; i<6 ; ++i) {
                    if(top[i] == '0') {
                        int r=i/3, c=i%3;
                        for(int k=0 ; k<4 ; ++k) {
                            int row=r+dir[k], col=c+dir[k+1];
                            if(row>=0 and row<2 and col>=0 and col<3) {
                                swap(top[r*3+c], top[row*3+col]);
                                if(s.count(top) == 0) {
                                    q.push(top);
                                    s.insert(top);
                                }
                                swap(top[r*3+c], top[row*3+col]);
                            }
                        }
                    }
                }
            }
            len++;
        }
        return -1;
    }
};
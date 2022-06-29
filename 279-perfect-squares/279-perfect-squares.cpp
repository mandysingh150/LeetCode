class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        q.push(n);
        vector<int> vis(n, 0);
        int len=0;
        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                auto top = q.front();
                q.pop();

                if(top == 0) {
                    return len;
                }
                
                for(int i=1 ; i*i<=top ; ++i) {
                    int val = top-i*i;
                    if(val == 0)
                        return 1+len;
                    if(!vis[val]) {
                        vis[val] = 1;
                        q.push(val);
                    }
                }
            }
            len++;
        }
        return 0;
    }
};
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& a) {
        int n=a.size(), ending_mask=(1<<n)-1;
        vector<vector<bool>> vis(n, vector<bool>(ending_mask+1, 0));
        // {current_node, mask}
        queue<pair<int,int>> q;
        for(int i=0 ; i<n ; ++i) {
            q.push({i, (1<<i)});
            vis[i][(1<<i)]=1;
        }
        int len = 0;
        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                auto [node, mask] = q.front(); 
                q.pop();
                if(mask == ending_mask)
                    return len;
                for(auto i: a[node]) {
                    int new_mask = (1<<i)|mask;
                    if(!vis[i][new_mask]) {
                        q.push({i, new_mask});
                        vis[i][new_mask]=1;
                    }                        
                }
            }
            len++;
        }
        return -1;
    }
};
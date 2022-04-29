class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), -1);
        for(int j=0 ; j<graph.size() ; ++j) {
            if(vis[j] != -1)
                continue;
            queue<int> q;
            q.push(j);
            vis[j]=0;
            while(!q.empty()) {
                auto top = q.front();
                q.pop();

                for(auto i: graph[top]) {
                    if(vis[i] == -1) {
                        vis[i] = 1-vis[top];
                        q.push(i);
                    }
                    else if(vis[i] == vis[top])
                        return 0;
                }
            }
        }
        return 1;
    }
};
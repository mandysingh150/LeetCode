class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> part(n, -1);    // can be partitions - 0 and 1
        queue<int> q;
        for(int j=0 ; j<n ; ++j) {
            if(part[j] > -1)
                continue;
            q.push(j);
            part[j] = 0;
            while(!q.empty()) {
                auto node = q.front();
                q.pop();

                for(auto i: g[node]) {
                    if(part[i] == -1) {
                        part[i] = 1-part[node];
                        q.push(i);
                    }
                    if(part[i] == part[node])
                        return 0;
                }
            }
        }
        return 1;
    }
};
class Solution {
public:
    unordered_map<int,vector<int>> mp;
    int dfs(int node, vector<int> &time, vector<int> &dist) {
        if(dist[node] != -1) {
            return dist[node];
        }
        int ans = time[node-1];
        for(auto ng: mp[node]) {
            ans = max(ans, time[node-1] + dfs(ng, time, dist));
        }
        return dist[node] = ans;
    }
    int minimumTime(int n, vector<vector<int>>& a, vector<int>& time) {
        vector<int> indegree(n+1, 0);
        for(auto i: a) {
            mp[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        vector<int> v, dist(n+1, -1);
        for(int i=1 ; i<=n ; ++i) {
            if(indegree[i] == 0) {
                v.push_back(i);
            }
        }
        int ans=0;
        for(auto ele: v) {
            ans = max(ans, dfs(ele, time, dist));
        }
        return ans;
    }
};
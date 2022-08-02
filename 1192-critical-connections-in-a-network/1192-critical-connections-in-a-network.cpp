class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int,vector<int>> mp;
    void tarjan_dfs(int node, int parent, int &cur_time, vector<int> &low, vector<int> &time, vector<int> &vis) {
        vis[node] = 1;
        low[node] = time[node] = ++cur_time;
        
        for(auto ng: mp[node]) {
            if(ng == parent) continue;
            
            if(!vis[ng]) {
                tarjan_dfs(ng, node, cur_time, low, time, vis);
                low[node] = min(low[node], low[ng]);
                if(low[ng] > time[node]) {
                    ans.push_back({ng, node});
                }
            }
            else {
                low[node] = min(low[node], time[ng]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(auto i: connections) {
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        vector<int> low(n), time(n), vis(n, 0);
        int t=0;
        tarjan_dfs(0, -1, t, low, time, vis);
        return ans;
    }
};
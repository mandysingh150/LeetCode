class Solution {
public:
    unordered_map<int,vector<int>> mp;
    int minimumTime(int n, vector<vector<int>>& a, vector<int>& time) {
        vector<int> indegree(n, 0);
        for(auto i: a) {
            mp[i[0]-1].push_back(i[1]-1);
            indegree[i[1]-1]++;
        }
        queue<int> q;
        vector<int> dist(n, 0);
        for(int i=0 ; i<n ; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
                dist[i] += time[i];
            }
        }
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            
            for(auto ng: mp[node]) {
                dist[ng] = max(dist[node] + time[ng], dist[ng]);
                if(--indegree[ng] == 0) {
                    q.push(ng);
                }
            }
        }
        return *max_element(begin(dist), end(dist));
    }
};
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>> mp;
        vector<int> indegree(n, 0);
        for(auto i: pre) {
            mp[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int> q;
        int cnt=0;
        for(int i=0 ; i<n ; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
                cnt++;
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            ans.push_back(top);
            for(auto ng: mp[top]) {
                if(--indegree[ng] == 0) {
                    q.push(ng);
                    cnt++;
                }
            }
        }
        return (cnt == n ? ans : vector<int>());
    }
};
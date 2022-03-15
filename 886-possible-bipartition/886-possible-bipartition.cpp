class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> mp;
        for(auto i: dislikes) {
            mp[i[0]].emplace_back(i[1]);
            mp[i[1]].emplace_back(i[0]);
        }
        vector<int> group(n+1, -1);       // groups are 0 and 1, -1 means unvisited/unallocated
        for(int i=1 ; i<n ; ++i) {
            if(group[i] != -1)
                continue;
            queue<int> q;
            q.push(i);
            group[i] = 0;
            while(!q.empty()) {
                auto node = q.front();
                q.pop();
                for(auto neg: mp[node]) {
                    if(group[neg] == -1) {
                        q.push(neg);
                        group[neg] = 1-group[node];
                    }
                    if(group[neg] == group[node])
                        return 0;
                }
            }
        }
        return 1;
    }
};
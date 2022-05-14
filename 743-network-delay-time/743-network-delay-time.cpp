class Solution {
public:
    vector<int> distance;
    unordered_map<int,vector<pair<int,int>>> mp;
    void dfs(int source, int elapsed) {
        if(distance[source] <= elapsed)
            return;
        distance[source] = elapsed;
        for(auto [destination, travel_time]: mp[source])
            dfs(destination, elapsed + travel_time);
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        distance.resize(n+1, INT_MAX);
        distance[0] = 0;
        for(auto i: times) mp[i[0]].push_back({i[1], i[2]});
        dfs(k, 0);
        int mx = *max_element(distance.begin(), distance.end());
        return mx==INT_MAX ? -1 : mx;
    }
};
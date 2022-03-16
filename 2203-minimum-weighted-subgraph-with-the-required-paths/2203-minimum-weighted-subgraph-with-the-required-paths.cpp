// for sparse graphs, using PRIORITY_QUEUE
const long long INF = LLONG_MAX;

void dijkstra(int n, int source, vector<long long> &distance_from_source, vector<vector<pair<int,int>>> &mp) {
    distance_from_source[source] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, source});
    while(!q.empty()) {
        auto [distance_from_vertex, vertex] = q.top();
        q.pop();
        
        if(distance_from_vertex > distance_from_source[vertex])
            continue;

        for(auto [to, len]: mp[vertex]) {
            if(distance_from_source[vertex] + len < distance_from_source[to]) {
                distance_from_source[to] = distance_from_source[vertex] + len;
                q.push({distance_from_source[to], to});
            }
        }
    }
    // now the "distance_from_source" vector consits of the distance of all nodes form the given "source" node
}

class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>> mp(n), reverse_mp(n);
        for(auto &i: edges) {
            mp[i[0]].push_back({i[1], i[2]});
            reverse_mp[i[1]].push_back({i[0], i[2]});
        }
        vector<long long> dist_src1(n, INF), dist_src2(n, INF), dist_destination(n, INF);
        dijkstra(n, src1, dist_src1, mp);
        dijkstra(n, src2, dist_src2, mp);
        dijkstra(n, dest, dist_destination, reverse_mp);
        long long ans=INF;
        for(int i=0 ; i<n ; ++i) {
            if(dist_src1[i]==INF or dist_src2[i]==INF or dist_destination[i]==INF)
                continue;
            ans = min(ans, dist_src1[i]+dist_src2[i]+dist_destination[i]);
        }
        return ans==INF ? -1 : ans;
    }
};
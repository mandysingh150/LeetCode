class Solution {
public:
    int find(vector<int> &p, int node) {
        return p[node] < 0 ? node : p[node] = find(p, p[node]);
    }
    int minCostConnectPoints(vector<vector<int>>& a) {
        // implementing Kruskal's algorithm
        int n=a.size(), ans=0;
        // if dsu[i]==-ve, then abs(dsu[i]) gives the tree size of node 'i'
        vector<int> dsu(n, -1);
        vector<array<int,3>> v;
        for(int i=0 ; i<n ; ++i) {
            for(int j=i+1 ; j<n ; ++j) {
                v.push_back({abs(a[i][0]-a[j][0]) + abs(a[i][1]-a[j][1]), i, j});
            }
        }
        make_heap(begin(v), end(v), greater<array<int,3>>());
        while(!v.empty()) {
            pop_heap(begin(v), end(v), greater<array<int,3>>());
            auto [distance, n1, n2] = v.back();
            v.pop_back();
            n1 = find(dsu, n1), n2 = find(dsu, n2);
            if(n1 != n2) {
                // take union
                ans += distance;
                
                // abs(dsu[n1]) nodes will be added to the tree with parent 'n2'
                dsu[n2] += dsu[n1];
                // changing parent of tree 'n1' to 'n2'
                dsu[n1] = n2;
                
                if(dsu[n2] == -n) {
                    break;
                }
            }
        }
        return ans;
    }
};
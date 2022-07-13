// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
int node_color[21];
bool h(int node, unordered_map<int,vector<int>> &mp, int m, int n) {
    if(node == n) {
        return 1;
    }
    int color_used[21]={0};
    for(auto ng: mp[node]) {
        if(node_color[ng]>0) {
            color_used[node_color[ng]] = 1;
        }
    }
    for(int i=1 ; i<=m ; ++i) {
        // bool possible_to_assign=1;
        // for(auto ng: mp[node]) {
        //     if(node_color[ng] == i) {
        //         possible_to_assign = 0;
        //         break;
        //     }
        // }
        // if(possible_to_assign) {
        if(!color_used[i]) {
            node_color[node] = i;
            if(h(node+1, mp, m, n)) {
                return 1;
            }
            // bool all_done = 1;
            // for(auto ng: mp[node]) {
            //     if(node_color[ng] == 0) {
            //         all_done &= h(ng, mp, m, n);
            //     }
            // }
            // if(all_done) {
            //     return 1;
            // }
            node_color[node] = 0;
        }
    }
    // vis[node] = 0;
    return 0;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    memset(node_color, 0, sizeof(node_color));
    unordered_map<int,vector<int>> mp;
    for(int i=0 ; i<n ; ++i) {
        for(int j=0 ; j<n ; ++j) {
            if(graph[i][j]) {
                mp[i].push_back(j);
                mp[j].push_back(i);
            }
        }
    }
    // bool ans=1;
    // for(int i=0 ; i<n ; ++i) {
    //     if(node_color[i] == 0) {
    //         ans &= h(i, mp, m, n);
    //     }
    // }
    // return ans;
    return h(0, mp, m, n);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
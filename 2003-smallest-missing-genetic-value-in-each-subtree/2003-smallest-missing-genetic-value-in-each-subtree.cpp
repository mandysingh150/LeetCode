class Solution {
public:
    void dfs(int node, unordered_map<int,vector<int>> &mp, vector<int> &vis, vector<int> &a) {
        vis[a[node]]=1;
        for(auto i: mp[node]) {
            if(!vis[a[i]]) {
                dfs(i, mp, vis, a);
            }
        }
    }
    vector<int> smallestMissingValueSubtree(vector<int>& p, vector<int>& a) {
        int n = p.size();
        vector<int> v(n, 1), vis(n+2, 0);
        unordered_map<int,vector<int>> mp;
        for(int i=1 ; i<n ; ++i) {
            mp[p[i]].push_back(i);
        }
        int node=find(begin(a), end(a), 1)-begin(a), mex=1;
        while(node > -1 and node<a.size()) {
            dfs(node, mp, vis, a);
            while(vis[mex])
                mex++;
            v[node] = mex;
            node = p[node];
        }
        return v;
    }
};
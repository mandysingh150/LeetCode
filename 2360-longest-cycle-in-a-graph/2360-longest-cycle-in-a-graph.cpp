class Solution {
public:
    int mx;
    void dfs(int node, vector<int> &e, vector<int> &a, vector<int> &vis, int len) {
        if(!vis[node]) {
            vis[node] = 1;
            a[node] = len;
            if(e[node] != -1) {
                dfs(e[node], e, a, vis, len+1);
            }
            a[node] = -1;
        }
        else {
            if(a[node] != -1) {
                mx = max(len-a[node], mx);
            }class Solution
{
public:
    int mx;
    void dfs(int node, vector<int> &edges, vector<int> &distance_from_start_node, vector<int> &visited, int current_len)
    {
        if (!visited[node]) {
            // adding the current node to the path form start node
            visited[node] = 1;
            distance_from_start_node[node] = current_len;

            if (edges[node] != -1) {
                dfs(edges[node], edges, distance_from_start_node, visited, current_len + 1);
            }
            
            // backtracking step - removing the current node from the path
            distance_from_start_node[node] = -1;
        }
        else {
            // checking if the current node makes a cycle or not
            if (distance_from_start_node[node] != -1) {
                // if it makes a cycle, then consider the number of nodes in the cycle
                mx = max(current_len - distance_from_start_node[node], mx);
            }
        }
    }
    int longestCycle(vector<int> &edges)
    {
        mx = -1;
        vector<int> visited(edges.size(), 0), length(edges.size(), -1);
        for (int i = 0; i < edges.size(); ++i) {
            if (!visited[i]) {
                dfs(i, edges, length, visited, 0);
            }
        }
        return mx;
    }
};
        }
    }
    int longestCycle(vector<int>& e) {
        mx=-1;
        vector<int> vis(e.size(), 0), len(e.size(), -1);
        for(int i=0 ; i<e.size() ; ++i) {
            if(!vis[i]) {
                dfs(i, e, len, vis, 0);
            }
        }
        return mx;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& a) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int ans=0, cnt=1;
        vector<bool> vis(a.size(), 0);
        vis[0] = 1;
        for(int j=1 ; j<a.size() ; ++j) {
            pq.push({abs(a[0][0]-a[j][0]) + abs(a[0][1]-a[j][1]), j});
        }
        while(!pq.empty() and cnt<a.size()) {
            while(vis[pq.top().second]) pq.pop();
            auto [dist, in] = pq.top();
            pq.pop();
            
            vis[in] = 1;
            ans += dist;
            cnt++;
            
            for(int j=0 ; j<a.size() ; ++j) {
                if(!vis[j]) {
                    pq.push({abs(a[in][0]-a[j][0]) + abs(a[in][1]-a[j][1]), j});
                }
            }
        }
        return ans;
    }
};
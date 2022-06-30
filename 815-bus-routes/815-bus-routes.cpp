class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return 0;
        
        unordered_set<int> s[501];
        for(int i=0 ; i<routes.size() ; ++i) {
            for(auto e: routes[i]) {
                s[i].insert(e);
            }
        }
        bool vis[1000000]={0};
        queue<int> q;
        q.push(source);
        vis[source]=1;
        int len=0;
        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                auto top = q.front();
                q.pop();
                
                for(int i=0 ; i<routes.size() ; ++i) {
                    if(s[i].count(top)) {
                        for(auto ng: s[i]) {
                            if(ng == target)
                                return len+1;
                            if(!vis[ng]) {
                                vis[ng] = 1;
                                q.push(ng);
                            }
                        }
                        s[i].clear();
                    }
                }
            }
            len++;
        }
        return -1;
    }
};
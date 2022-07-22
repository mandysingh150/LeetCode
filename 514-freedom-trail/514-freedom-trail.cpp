int dp[105][105];
class Solution {
public:
    int findRotateSteps(string &ring, string &key) {
        vector<int> pos[26];
        int r = ring.size();
        for(int i=0;i<r;i++) pos[ring[i]-'a'].push_back(i);
        memset(dp, -1, sizeof(dp));
        return findSteps(0, 0, ring, key, pos);
    }
    int findSteps(int p1, int p2, string &ring, string &key, vector<int> pos[26]) {
        if(p2==key.size()) return 0;
        if(dp[p1][p2] != -1) return dp[p1][p2];
        int r = ring.size(), ms=INT_MAX;
        for(int nxt:pos[key[p2]-'a']) {
            int dist = abs(p1-nxt);
            ms = min(ms, min(dist, r-dist) + findSteps(nxt, p2+1, ring, key, pos));    
        }
        return dp[p1][p2]=ms+1;
    }
};
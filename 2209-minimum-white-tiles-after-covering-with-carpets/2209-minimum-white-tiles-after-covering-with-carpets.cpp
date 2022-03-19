class Solution {
public:
    vector<vector<int>> dp;
    int help(string &floor, int n_carpets, int &carpetLen, int i) {
        if(i>=floor.size())
            return 0;
        if(dp[i][n_carpets] != -1)
            return dp[i][n_carpets];
        int a1 = (floor[i]=='1') + help(floor, n_carpets, carpetLen, i+1), a2=INT_MAX;
        if(floor[i]=='1' and n_carpets>0)
            a2 = help(floor, n_carpets-1, carpetLen, i+carpetLen);
        return dp[i][n_carpets] = min(a1, a2);
    }
    int minimumWhiteTiles(string &floor, int numCarpets, int carpetLen) {
        int n=floor.size();
        dp.assign(n, vector<int>(numCarpets+1, -1));
        return help(floor, numCarpets, carpetLen, 0);
    }
};
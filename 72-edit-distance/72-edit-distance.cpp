class Solution {
public:
    int minDistance(string word1, string word2) {
        // replace = i-1, j-1
        // add = i, j-1
        // remove = i-1, j
        int dp[word1.size()+1][word2.size()+1];
        for(int i=0 ; i<=word1.size() ; ++i) {
            for(int j=0 ; j<=word2.size() ; ++j) {
                if(i==0 or j==0)
                    dp[i][j] = i==0 ? j : i;
                else {
                    if(word1[i-1] == word2[j-1])
                        dp[i][j] = dp[i-1][j-1];
                    else
                        dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
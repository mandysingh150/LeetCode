class Solution {
public:
    int largestVariance(string &s) {
        // understood from post by "dm_a"
        
        int ans=0;
        for(char i='a' ; i<='z' ; ++i) {
            for(char j='a' ; j<='z' ; ++j) {
                if(i != j) {
                    // 'i' is the high frequency character
                    // 'j' is the low frequency character
                    int i_count=0, j_count=0;
                    bool can_use_previously_occured_j=0;
                    for(auto ch: s) {
                        if(ch == i) i_count++;
                        if(ch == j) j_count++;
                        
                        if(j_count > 0) {
                            ans = max(ans, i_count-j_count);
                        }
                        else if(j_count==0 and can_use_previously_occured_j) {
                            // using previously occured 'j', so subtracting "1" from 'i_count'
                            ans = max(ans, i_count - 1);
                        }
                        
                        if(j_count > i_count) {
                            // reset the counts of i and j
                            i_count = j_count = 0;
                            can_use_previously_occured_j = 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
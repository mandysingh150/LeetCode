class Solution {
public:
    int largestVariance(string &s) {
        int mx=0;
        // assuming 'ch1' has higher frequency than 'ch2'
        for(char ch1='a' ; ch1<='z' ; ++ch1) {
            for(char ch2='a'; ch2<='z' ; ++ch2) {
                if(ch1 == ch2)
                    continue;
                
                int c1=0, c2=0;
                bool can_use_prev_c2=0;
                for(int i=0 ; i<s.size() ; ++i) {
                    if(s[i] == ch1) c1++;
                    if(s[i] == ch2) c2++;
                    
                    if(c2>0) {
                        mx = max(mx, c1-c2);
                    }
                    else if(c2==0 and can_use_prev_c2) {
                        mx = max(mx, c1-1);
                    }
                    
                    if(c1 < c2) {
                        c1=c2=0;
                        can_use_prev_c2 = 1;
                    }
                }
            }
        }
        return mx;
    }
};
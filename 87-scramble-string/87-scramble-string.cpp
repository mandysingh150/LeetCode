int mem[30][30][30][30];
class Solution {
public:
    bool h(string &s1, int si1, int ei1, string &s2, int si2, int ei2) {
        if(si1 == ei1) {
            return s1[si1] == s2[si2];
        }
        if(mem[si1][ei1][si2][ei2] != -1) {
            return mem[si1][ei1][si2][ei2];
        }
        int found=0;
        for(int i=si1 ; i<ei1 ; ++i) {
            if((h(s1, si1, i, s2, si2, si2+(i-si1)) and h(s1, i+1, ei1, s2, ei2-(ei1-i-1), ei2)) or 
                    (h(s1, i+1, ei1, s2, si2, si2+(ei1-i-1)) and h(s1, si1, i, s2, ei2-(i-si1), ei2))) {
                found=1;
                break;
            }
        }
        return mem[si1][ei1][si2][ei2] = found;
    }
    bool isScramble(string s1, string s2) {
        memset(mem, -1, sizeof(mem));
        return h(s1, 0, s1.size()-1, s2, 0, s2.size()-1);
    }
};
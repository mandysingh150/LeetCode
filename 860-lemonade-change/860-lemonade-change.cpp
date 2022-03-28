class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt_5=0, cnt_10=0;
        for(auto i: bills) {
            if(i==5) {
                cnt_5++;
            }
            else if(i==10) {
                if(cnt_5 == 0)
                    return 0;
                cnt_5--;
                cnt_10++;
            }
            else {
                if(cnt_10 == 0) {
                    if(cnt_5 < 3)
                        return 0;
                    cnt_5 -= 3;
                }
                else {
                    cnt_10--;
                    if(cnt_5 == 0)
                        return 0;
                    cnt_5--;
                }                
            }
        }
        return 1;
    }
};
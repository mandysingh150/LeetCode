class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int cnt=0, multiple=(minutesToTest/minutesToDie)+1, val=1;
        while(val < buckets) {
            val *= multiple;
            cnt++;
        }
        return cnt;
    }
};
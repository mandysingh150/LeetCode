class Solution {
public:
    bool help(vector<int> &a, int in, int cnt[]) {
        if(in == a.size()) {
            return cnt[0]==0 and cnt[1]==0 and cnt[2]==0 and cnt[3]==0;
            //+cnt[1]-cnt[2]-cnt[3] == 0;
        }
        for(int i=0 ; i<4 ; ++i) {
            if(cnt[i]-a[in] >= 0) {
                cnt[i] -= a[in];
                if(help(a, in+1, cnt)) {
                    return 1;
                }
                cnt[i] += a[in];
            }
        }
        return 0;
    }
    bool makesquare(vector<int>& a) {
        int sum=accumulate(begin(a), end(a), 0ll);
        if(sum%4 or *max_element(begin(a), end(a))>sum/4) return 0;
        sum /= 4;
        int cnt[4]={sum, sum, sum, sum};
        sort(begin(a), end(a), greater<int>());
        return help(a, 0, cnt);
    }
};
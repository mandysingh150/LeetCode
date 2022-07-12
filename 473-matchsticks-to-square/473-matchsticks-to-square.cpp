class Solution {
public:
    bool help(vector<int> &a, int in, vector<int> &v, int sum) {
        if(in == a.size()) {
            return v[0]+v[1]-v[2]-v[3]==0;
        }
        for(int i=0 ; i<4 ; ++i) {
            if(v[i]+a[in] <= sum) {
                v[i] += a[in];
                if(help(a, in+1, v, sum)) {
                    return 1;
                }
                v[i] -= a[in];
            }
        }
        return 0;
    }
    bool makesquare(vector<int>& a) {
        int n=a.size(), sum_req=accumulate(begin(a), end(a), 0), mx=*max_element(begin(a), end(a));
        if(sum_req%4 or mx>(sum_req/4)) {
            return 0;
        }
        sum_req/=4;
        vector<int> sums(4, 0);
        sort(begin(a), end(a), greater<int>());
        return help(a, 0, sums, sum_req);
    }
};
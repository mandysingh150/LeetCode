class Solution {
public:
    int maximumBags(vector<int>& a, vector<int>& b, int additionalRocks) {
        for(int i=0 ; i<a.size() ; ++i) {
            a[i] -= b[i];
        }
        sort(begin(a), end(a));
        if(additionalRocks < a[0])
            return 0;
        int cnt=0;
        while(cnt<a.size() and additionalRocks >= a[cnt]) {
            additionalRocks -= a[cnt];
            ++cnt;
        }
        return cnt;
    }
};
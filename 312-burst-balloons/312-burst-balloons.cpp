class Solution {
public:
    int mp[500][500];
    int h(vector<int>& a, int si, int ei) {
        if(si>ei)
            return 0;
        if(mp[si][ei] != -1)
            return mp[si][ei];
        
        int leftValue = si-1<0 ? 1 : a[si-1];
        int rightValue = ei+1>=a.size() ? 1 : a[ei+1];
        int maxValue = 0;
        for(int i=si ; i<=ei ; ++i) {
            int left_ans = h(a, si, i-1);
            int right_ans = h(a, i+1, ei);
            maxValue = max(maxValue, (leftValue*a[i]*rightValue) + left_ans + right_ans);
        }
        return mp[si][ei] = maxValue;
    }
    int maxCoins(vector<int>& a) {
        memset(mp, -1, sizeof(mp));
        return h(a, 0, a.size()-1);
    }
};
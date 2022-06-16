class Solution {
public:
    int minCost(vector<int>& st, vector<int>& hm, vector<int>& rc, vector<int>& cc) {
        int ans=0;
        for(int r=st[0]+(st[0]<=hm[0] ? 1 : -1) ; (st[0]<=hm[0] ? r<=hm[0] : r>=hm[0]) ; (st[0]<=hm[0] ? ++r : --r)) {
            ans += rc[r];
        }
        for(int c=st[1]+(st[1]<=hm[1] ? 1 : -1) ; (st[1]<=hm[1] ? c<=hm[1] : c>=hm[1]) ; (st[1]<=hm[1] ? ++c : --c)) {
            ans += cc[c];
        }
        return ans;
    }
};
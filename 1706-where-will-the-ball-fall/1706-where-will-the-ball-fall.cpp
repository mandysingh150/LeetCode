class Solution {
public:
    vector<int> findBall(vector<vector<int>>& a) {
        vector<int> v;
        for(int i=0 ; i<a[0].size() ; ++i) {
            int c=i, possible=1;
            for(int r=0 ; r<a.size() ; ++r) {
                if(c+a[r][c]<0 or c+a[r][c]>=a[0].size() or a[r][c]!=a[r][c+a[r][c]]) {
                    possible = 0;
                    break;
                }
                c += a[r][c];
            }
            v.push_back(possible and c>=0 and c<a[0].size() ? c : -1);
        }
        return v;
    }
};
#define ll long long
class Solution {
public:
    ll pyramid(vector<vector<int>>& a, vector<vector<ll>>& v, int r, int c, bool inv) {
        ll sign = (inv ? -1 : 1);
        ll cnt=0, i=r+sign, j=c, h=2, val=(2*h-1)/2;
        while(i>=0 and i<a.size() and a[i][j]==1 and (c-val)>=0 and (c+val)<a[0].size() and v[i][c+val+1]-v[i][c-val]==(2*h-1)) {
            ++cnt;
            i += sign;
            h++;
            val=(2*h-1)/2;
        }
        return cnt;
    }
    
    int h(vector<vector<int>> &a) {
        int m=a.size(), n=a[0].size(), ans=0;
        // counting all inverse pyramids
        for(int i=1 ; i<m ; ++i) {
            for(int j=1 ; j<n-1 ; ++j) {
                if(a[i][j]) {
                    a[i][j] = 1 + min(a[i-1][j-1], min(a[i-1][j], a[i-1][j+1]));
                    
                    // pyramid of height 'h' adds 'h-1' pyramids to the answer
                    ans += a[i][j] - 1;
                }
            }
        }
        return ans;
    }
    
    int countPyramids(vector<vector<int>>& a) {
        // APPROACH 1 - make prefix array for each row and then count all pyramids
//         int m=a.size(), n=a[0].size();
//         vector<vector<ll>> v(m, vector<ll>(n+1, 0ll));
//         for(int i=0 ; i<m ; ++i) {
//             for(int j=0 ; j<n ; ++j) {
//                 v[i][j+1] = v[i][j] + a[i][j];
//             }
//         }
        
//         ll ans = 0;
//         for(int i=0 ; i<m ; ++i) {
//             for(int j=0 ; j<n ; ++j) {
//                 if(a[i][j]==1) {
//                     ans += pyramid(a, v, i, j, 0) + pyramid(a, v, i, j, 1);
//                 }
//             }
//         }
//         return ans;
        
        // APPROACH 2 - DP solution
        vector<vector<int>> reverse_a(rbegin(a), rend(a));
        // count_inverse_pyramids + count_inverse_pyramids_for_reverse_matrix
        return h(a) + h(reverse_a);
    }
};
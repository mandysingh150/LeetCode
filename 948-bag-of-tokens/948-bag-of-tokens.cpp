class Solution {
public:
    int bagOfTokensScore(vector<int>& a, int p) {
        sort(begin(a), end(a));
        int i=0, j=a.size()-1, mx=0, score=0;
        while(i<=j) {
            bool move=0;
            while(i<=j and a[i]<=p) {
                p -= a[i++];
                mx = max(mx, ++score);
                move=1;
            }
            if(i<=j and score>0) {
                p += a[j--];
                move=1;
                score--;
            }
            if(!move) break;
        }
        return mx;
    }
};
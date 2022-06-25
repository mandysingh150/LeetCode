class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        int cnt_dips=0;
        for(int i=1 ; i<a.size() ; ++i) {
            if(a[i-1] > a[i]) {
                if(i-2<0 or a[i-2]<=a[i]) {
                    a[i-1]=a[i];
                }
                else {
                    a[i]=a[i-1];
                }
                cnt_dips++;
            }
        }
        return cnt_dips<=1;
    }
};
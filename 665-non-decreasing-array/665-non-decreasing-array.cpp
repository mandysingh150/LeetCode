class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        int cnt_dips=0;
        for(int i=1 ; i<a.size() ; ++i) {
            if(a[i-1] > a[i]) {
                if(i-2<0) {
                    // as 'i-1' is the 0th index, we can make array non-decreasing by changing a[i-1], iff a[1] to a[n-1] is non-decreasing
                    a[i-1]=a[i];
                }
                else if(a[i-2]<=a[i]) {
                    // here (a[i-2] <= a[i-1] >= a[i]), we can make it no-decreasing by changing a[i-1] to a[i]
                    a[i-1]=a[i];
                }
                else {
                    // here (a[i-2] <= a[i-1] >= a[i]) and (a[i-2] > a[i]), so we can make it non-decreasing by changing a[i] to a[i-1]
                    a[i]=a[i-1];
                }
                cnt_dips++;
            }
        }
        return cnt_dips<=1;
    }
};
class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int in=a.size()-2, j=in+1;
        while(in>=0 and a[in] >= a[in+1])
            in--;
        if(in<0) {
            sort(begin(a), end(a));
        }
        else {
            while(j>=0 and a[in] >= a[j])
                j--;
            swap(a[in], a[j]);
            reverse(a.begin()+in+1, a.end());
        }
    }
};
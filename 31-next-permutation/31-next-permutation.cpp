class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int in=a.size()-1, j=in;
        while(in>=1 and a[in-1] >= a[in])
            in--;
        if(in==0) {
            sort(begin(a), end(a));
        }
        else {
            while(a[in-1] >= a[j])
                j--;
            swap(a[in-1], a[j]);
            reverse(a.begin()+in, a.end());
        }
    }
};
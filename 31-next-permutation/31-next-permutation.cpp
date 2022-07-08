class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n=a.size(), i=n-2, j=n-1;
        while(i>=0 and a[i]>=a[i+1]) --i;
        if(i>=0) {
            while(i<j and a[i]>=a[j]) --j;
            swap(a[i], a[j]);
        }
        reverse(begin(a)+i+1, end(a));
    }
};
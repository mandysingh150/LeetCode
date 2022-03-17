class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int i=a.size()-1, j=i;
        while(i>=1 and a[i]<=a[i-1]) i--;
        if(i==0)
            sort(begin(a), end(a));
        else {
            while(a[j]<=a[i-1]) j--;
            swap(a[i-1], a[j]);
            reverse(begin(a)+i, end(a));
        }
    }
};
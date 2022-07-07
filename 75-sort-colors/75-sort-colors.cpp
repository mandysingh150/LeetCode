class Solution {
public:
    void sortColors(vector<int>& a) {
        int in_0=0, i=0, in_2=a.size()-1;
        while(i<=in_2) {
            if(a[i] == 0) {
                swap(a[in_0], a[i]);
                in_0++;
                i++;
            }
            else if(a[i] == 1) {
                i++;
            }
            else {
                swap(a[in_2], a[i]);
                in_2--;
                // i++;
            }
        }
    }
};
class Solution {
public:
    int search(vector<int>& a, int x) {
        int l=0, h=a.size()-1;
        while(l<=h) {
            int mid = (l+h)>>1;
            if(a[mid] == x) {
                return mid;
            }
            else if(a[l] <= a[mid]) {
                if(a[l] <= x and x <= a[mid]) {
                    h=mid-1;
                }
                else {
                    l=mid+1;
                }
            }
            else {
                if(a[mid] <= x and x <= a[h]) {
                    l=mid+1;
                }
                else {
                    h=mid-1;
                }
            }
        }
        return -1;
    }
};
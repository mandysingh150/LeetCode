class Solution {
public:
    int findMin(vector<int>& a) {
        int l=0, h=a.size()-1;
        while(l<h) {
            int mid = (l+h)>>1;
            if(a[mid] < a[h])      // non-decreasing order
                h=mid;
            else if(a[mid] > a[h])        // decreasing order
                l=mid+1;
            else
                h--;
        }
        return a[h];
    }
};
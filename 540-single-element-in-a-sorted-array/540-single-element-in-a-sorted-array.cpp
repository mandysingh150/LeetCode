class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        if(a.size()==1)
            return a[0];
        int l=0, h=a.size()-1;
        while(l<=h) {
            int mid=(l+h)>>1;
            if(mid&1) {
                if(a[mid]==a[mid-1]) {
                    l=mid+1;
                }
                else {
                    h=mid-1;
                }
            }
            else {
                if(a[mid]==a[mid+1]) {
                    l=mid+1;
                }
                else {
                    h=mid-1;
                }
            }
        }
        return a[l];
    }
};
class Solution {
public:
    int search(vector<int>& a, int x) {
        int k, l=0, h=a.size()-1;
        while(l<h) {
            int mid=(l+h)>>1;
            if(a[mid] <= a[h]) {
                h=mid;
            }
            else {
                l=mid+1;
            }
        }
        k=l;
        l=0, h=a.size()-1;
        while(l<=h) {
            int mid=(l+h)>>1, new_mid=(k+mid)%a.size();
            if(a[new_mid] == x) {
                return new_mid;
            }
            else if(a[new_mid] < x) {
                l=mid+1;
            }
            else {
                h=mid-1;
            }
        }
        return -1;
    }
};
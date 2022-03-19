class Solution {
public:
    int search(vector<int>& a, int x) {
        int rot, l=0, h=a.size()-1;
        while(l<h) {
            int mid=(l+h)>>1;
            if(a[mid] > a[h])
                l=mid+1;
            else
                h=mid;
        }
        rot=l;
        l=0,h=a.size()-1;
        while(l<=h) {
            int mid=(l+h)>>1;
            int shifted_mid = (mid+rot)%a.size();
            if(a[shifted_mid] == x)
                return shifted_mid;
            else if(a[shifted_mid] < x)
                l=mid+1;
            else
                h=mid-1;
        }
        return -1;
    }
};
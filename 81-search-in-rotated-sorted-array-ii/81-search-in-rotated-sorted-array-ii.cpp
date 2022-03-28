class Solution {
public:
    bool search(vector<int>& a, int target) {
        int l=0, h=a.size()-1, mid;
        while(l<h) {
            mid=(l+h)>>1;
            if(a[mid] == target)
                return 1;
            if(a[mid] < a[h]) {
                if(a[mid]<target and target<=a[h])
                    l=mid+1;
                else
                    h=mid;
            }
            else if(a[mid] > a[h]) {
                if(a[l]<=target and target<a[mid])
                    h=mid;
                else
                    l=mid+1;
            }
            else
                h--;    // to decrease the search space
        }
        return a[l]==target;
    }
};
class Solution {
public:
    int hIndex(vector<int>& a) {
        int l=0, h=a.size()-1, ans=0;
        while(l<=h) {
            int mid=(l+h)>>1;
            if(a.size()-mid <= a[mid])
                ans=a.size()-mid, h=mid-1;
            else
                l=mid+1;
        }
        return ans;
    }
};
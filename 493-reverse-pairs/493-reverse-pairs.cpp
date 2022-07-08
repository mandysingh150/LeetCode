int b[50005];
class Solution {
public:
    int merge(vector<int> &a, int si, int mid, int ei) {
        int i=si, j=mid+1, k=0, cnt=0;
        auto it = begin(a)+mid;
        for(int temp=mid+1 ; temp<=ei ; ++temp) {
            cnt += it - upper_bound(begin(a)+si, begin(a)+mid+1, 2ll*a[temp]) + 1;
        }
        while(i<=mid and j<=ei) {
            if(a[i] <= a[j]) b[k]=a[i++];
            else b[k]=a[j++];
            k++;
        }
        while(i<=mid) {
            b[k]=a[i++];
            k++;
        }
        while(j<=ei) {
            b[k]=a[j++];
            k++;
        }
        for(int t=0 ; t<k ; ++t) {
            a[si+t] = b[t];
        }
        return cnt;
    }
    int merge_sort(vector<int> &a, int si, int ei) {
        if(si >= ei)
            return 0;
        int mid = (si+ei)>>1;
        return merge_sort(a, si, mid) + merge_sort(a, mid+1, ei) + merge(a, si, mid, ei);
    }
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size()-1);
    }
};
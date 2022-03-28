class Solution {
public:
    bool search(vector<int>& a, int target) {
        for(int i=0 ; i<a.size() ; ++i)
            if(a[i] == target)
                return 1;
        return 0;
                
        // int l=0,h=a.size()-1;
        // while(l<h) {
        //     int mid=(l+h)>>1;
        //     if(a[mid]<a[h])
        //         h=mid;
        //     else if(a[mid] > a[h])
        //         l=mid+1;
        //     else 
        //         h--;
        // }
        // int k=l;    // 'l' is equal to 'h'
        // l=0, h=a.size()-1;
        // while(l<=h) {
        //     int mid=(l+h)>>1;
        //     int realMid=(mid+k)%a.size();
        //     if(a[realMid] == target)
        //         return 1;
        //     else if(a[realMid] < target)
        //         l=mid+1;
        //     else
        //         h=mid-1;
        // }
        // return 0;
    }
};
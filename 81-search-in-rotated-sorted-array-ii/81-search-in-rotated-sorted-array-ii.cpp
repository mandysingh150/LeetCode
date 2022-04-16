class Solution {
public:
    bool search(vector<int>& a, int x) {
        int l=0, h=a.size()-1;
        while(l<h) {
            int mid = (l+h)>>1;
            if(a[mid] == x)
                return 1;
            
            if(a[mid] < a[h])
                if(a[mid]<x and x<=a[h])
                    l=mid+1;
                else
                    h=mid;
            else if(a[mid] > a[h])
                if(a[l]<=x and x<a[mid])
                    h=mid;                    
                else
                    l=mid+1;
            else
                h--;
        }
        return a[l]==x;
    }
};
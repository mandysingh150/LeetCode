class Solution {
public:
    int smallestDivisor(vector<int>& a, int threshold) {
        int l=1, h=*max_element(begin(a), end(a)), ans;
        while(l<=h) {
            int mid = (l+h)>>1, sum=0;
            for(auto i: a) sum += ((i+mid-1)/mid);
            if(sum <= threshold)
                ans=mid, h=mid-1;
            else
                l=mid+1;
        }
        return ans;
    }
};
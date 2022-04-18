class Solution {
public:
    int minSpeedOnTime(vector<int>& a, double hour) {
        int l=1, h=1e7, ans=INT_MAX;
        while(l<=h) {
            int mid = (l+h)>>1;
            
            double sum=0;
            for(int i=0 ; i<a.size()-1 ; ++i)
                sum += (a[i]+mid-1)/mid;
            sum += (a.back()*1.00)/mid;
            
            if(sum <= hour)
                ans=mid, h=mid-1;
            else
                l=mid+1;
        }
        return ans==INT_MAX ? -1 : ans;
    }
};
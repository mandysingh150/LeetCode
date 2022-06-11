class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        int sum = accumulate(a.begin(), a.end(), 0);
        if(sum == x)
            return a.size();
        if(sum < x)
            return -1;

        int si=0, ei=a.size()-1, mn=INT_MAX;
        sum=x;
        bool increasing=1;
        while(1) {
            sum -= a[si];
            
            if(sum <= 0) {
                if(sum == 0)
                    mn = min(mn, si+1);
                sum += a[si];
                break;
            }
            si++;
        }
        si--;
        while(1) {
            sum -= a[ei];
            
            while(si>=0 and sum<0) {               
                sum += a[si];
                si--;                
            }
            if(sum == 0)
                mn = min(mn, int(a.size())-ei + si+1);
            ei--;
            if(sum<0)
                break;
        }
        return mn==INT_MAX ? -1 : mn;
    }
};
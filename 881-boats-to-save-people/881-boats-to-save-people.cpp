class Solution {
public:
    int numRescueBoats(vector<int>& a, int limit) {
        sort(begin(a), end(a));
        int i=0, j=a.size()-1, ans=0;
        while(i<=j) {
            if(i==j)
                return ans+1;
            else {
                if(a[i]+a[j]<=limit)
                    ++i;
                --j;
                ans++;
            }
        }
        return ans;
    }
};
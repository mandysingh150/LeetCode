class Solution {
public:
    int minCostClimbingStairs(vector<int>& a) {
        int n=a.size(), n1=a[n-2], n2=a[n-1], n0;
        for(int i=n-3 ; i>=0 ; --i) {
            n0 = a[i] + min(n1, n2);
            n2=n1;
            n1=n0;
        }
        return min(n1, n2);
    }
};
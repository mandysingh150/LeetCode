class Solution {
public:
    int threeSumClosest(vector<int>& a, int x) {
        sort(begin(a), end(a));
        pair<int,int> close={INT_MAX, 0};
        for(int i=0 ; i<a.size()-2 ; ++i) {
            for(int j=i+1, k=a.size()-1 ; j<k ; ) {
                int sum = a[i]+a[j]+a[k];
                if(abs(sum-x) < close.first)
                    close = {abs(sum-x), sum};
                if(sum == x)
                    return sum;
                else if(sum > x)
                    k--;
                else 
                    j++;
            }
        }
        return close.second;
    }
};
class Solution {
public:
    int pivotIndex(vector<int>& a) {
        long long right_sum = accumulate(begin(a), end(a), 0ll), left_sum=0;
        for(int i=0 ; i<a.size() ; ++i) {
            right_sum -= a[i];
            if(right_sum == left_sum) {
                return i;
            }
            left_sum += a[i];
        }
        return -1;
    }
};
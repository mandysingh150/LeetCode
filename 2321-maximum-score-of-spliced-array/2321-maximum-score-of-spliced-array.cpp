class Solution {
public:
    int kadane(vector<int> &a, vector<int> &b) {
        int sum=0, mx=0;
        for(int i=0 ; i<a.size() ; ++i) {
            sum += b[i]-a[i];
            if(sum < 0)
                sum=0;
            mx = max(mx, sum);
        }
        return mx;
    }
    int maximumsSplicedArray(vector<int>& n1, vector<int>& n2) {
        return max(accumulate(begin(n1), end(n1), 0ll)+kadane(n1, n2), accumulate(begin(n2), end(n2), 0ll)+kadane(n2, n1));
    }
};
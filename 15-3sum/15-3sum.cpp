class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> v;
        sort(begin(a), end(a));
        int n=a.size();
        for(int i=0 ; i<n ; ) {
            int j=i+1, k=n-1;
            while(j<k) {
                int sum = a[i]+a[j]+a[k];
                if(sum == 0) {
                    v.push_back({a[i], a[j], a[k]});
                    int node_j = a[j++];
                    while(j<k and a[j]==node_j) ++j;
                    int node_k = a[k--];
                    while(j<k and a[k]==node_k) --k;
                }
                else if(sum < 0) {
                    ++j;
                }
                else {
                    --k;
                }
            }
            int node_i = a[i++];
            while(i<n and a[i]==node_i) ++i;
        }
        return v;
    }
};
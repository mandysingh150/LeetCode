class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        priority_queue<int> pq;
        for(int i=0 ; i<a.size() ; ++i) {
            for(int j=0 ; j<a[0].size() ; ++j) {
                pq.push(a[i][j]);
                if(pq.size() > k) {
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};
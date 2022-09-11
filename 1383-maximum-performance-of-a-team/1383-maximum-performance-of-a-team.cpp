class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v;
        for(int i=0 ; i<n ; ++i) {
            v.push_back({efficiency[i], speed[i]});
        }
        
        // sorting the array based on decreasing efficiency
        sort(v.begin(), v.end(), [&] (pair<int,int> a, pair<int,int> b) {
            return a.first>b.first; 
        });
        
        long long ans=0, sumSpeed=0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i: v) {
            if(pq.size() == k) {    // if we have all elements, then to cconsider current element, the minimum element needs to be removed
                sumSpeed -= pq.top();   // remove engineer with minimum speed
                pq.pop();
            }
            
            sumSpeed += i.second;
            pq.push(i.second);
            ans = max(ans, sumSpeed*i.first);
        }
        return ans%(int)(1e9+7);
    }
};
class Solution {
public:
    int furthestBuilding(vector<int>& a, int br, int l) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0 ; i<a.size()-1 ; ++i) {
            int diff = a[i+1]-a[i];
            if(diff > 0) {
                pq.push(diff);
            }
            // we can use ladders for the maximum difference buildings and thus use bricks for the others
            if(pq.size() > l) { 
                br -= pq.top();
                pq.pop();
            }
            if(br < 0) {
                return i;
            }
        }
        return a.size()-1;
    }
};
class Solution {
public:
    int furthestBuilding(vector<int>& a, int br, int l) {
        priority_queue<int> pq;
        for(int i=1 ; i<a.size() ; ++i) {
            if(a[i-1] < a[i]) {
                pq.push(-(a[i]-a[i-1]));
                if(pq.size() > l) {
                    br += pq.top();
                    pq.pop();
                }
                if(br < 0) {
                    return i-1;
                }
            }
        }
        return a.size()-1;
    }
};
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& a) {
        priority_queue<int> pq;
        int time=0;
        sort(begin(a), end(a), [](vector<int> &c, vector<int> &d) {
            if(c[1] == d[1])
                return c[0]<d[0];
            return c[1]<d[1];
        });
        for(int i=0; i<a.size(); ++i) {
            if(time + a[i][0] <= a[i][1]){
                time += a[i][0];
                pq.push(a[i][0]);
            }
            else if(!pq.empty() and a[i][0]<pq.top()) {
                time += a[i][0] - pq.top();
                pq.pop();
                pq.push(a[i][0]);
            }
        }
        return pq.size();
    }
};
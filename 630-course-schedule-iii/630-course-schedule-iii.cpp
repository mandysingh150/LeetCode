class Solution {
public:
    int scheduleCourse(vector<vector<int>>& a) {
        priority_queue<int> pq;
        int time=0;
        sort(begin(a), end(a), [](auto &c, auto &d) {
            return c[1] < d[1];
        });
        for(auto i: a) {
            if(time + i[0] <= i[1]) {
                time += i[0];
                pq.push(i[0]);
            }
            else {
                if(!pq.empty() and pq.top() > i[0]) {
                    time += i[0] - pq.top();
                    pq.pop();
                    pq.push(i[0]);
                }
            }
        }
        return pq.size();
    }
};
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int time=0;
        priority_queue<int> pq;
        sort(begin(courses), end(courses), [](vector<int> &c, vector<int>&d) {
            return c[1]<d[1];
        });
        for(auto i: courses) {
            if(time + i[0] <= i[1]) {
                time += i[0];
                pq.push(i[0]);
            }
            else if(!pq.empty() and i[0] < pq.top()){
                time += i[0] - pq.top();
                pq.pop();
                pq.push(i[0]);
            }
        }
        return pq.size();
    }
};